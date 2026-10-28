#include <ctype.h>
#include <errno.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>

#include "arquivo.h"
#include "candidato.h"

#define CAMINHO_DADOS "data/candidatos.csv"

static void remover_quebra_linha(char *texto) {
    texto[strcspn(texto, "\r\n")] = '\0';
}

static int ler_linha(const char *mensagem, char *destino, size_t tamanho) {
    printf("%s", mensagem);
    if (fgets(destino, (int)tamanho, stdin) == NULL) {
        return 0;
    }

    if (strchr(destino, '\n') == NULL) {
        int caractere = getchar();
        if (caractere == '\r') {
            caractere = getchar();
        }
        if (caractere != '\n' && caractere != EOF) {
            while ((caractere = getchar()) != '\n' && caractere != EOF) {
            }
            printf("Entrada muito longa. Tente novamente.\n");
            return -1;
        }
    }

    remover_quebra_linha(destino);
    return 1;
}

static int ler_opcao(int *opcao) {
    char linha[32];
    char *fim;
    long valor;
    int resultado = ler_linha("\nOpcao: ", linha, sizeof(linha));

    if (resultado <= 0) {
        return resultado;
    }

    errno = 0;
    valor = strtol(linha, &fim, 10);
    while (isspace((unsigned char)*fim)) {
        fim++;
    }

    if (linha[0] == '\0' || *fim != '\0' || errno == ERANGE) {
        printf("Digite uma opcao valida.\n");
        return -1;
    }

    *opcao = (int)valor;
    return 1;
}

static int normalizar_cpf(const char *entrada, char cpf[12]) {
    size_t quantidade = 0;
    size_t i;

    for (i = 0; entrada[i] != '\0'; i++) {
        unsigned char caractere = (unsigned char)entrada[i];
        if (isdigit(caractere)) {
            if (quantidade >= 11) {
                return 0;
            }
            cpf[quantidade++] = (char)caractere;
        } else if (caractere != '.' && caractere != '-' && !isspace(caractere)) {
            return 0;
        }
    }

    cpf[quantidade] = '\0';
    return quantidade == 11;
}

static int data_valida(const char *data) {
    int dia;
    int mes;
    int ano;
    int dias_no_mes;
    int bissexto;
    char sobra;
    static const int dias[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

    if (sscanf(data, "%2d/%2d/%4d%c", &dia, &mes, &ano, &sobra) != 3 ||
        strlen(data) != 10 || data[2] != '/' || data[5] != '/') {
        return 0;
    }

    if (ano < 1 || mes < 1 || mes > 12) {
        return 0;
    }

    bissexto = (ano % 4 == 0 && ano % 100 != 0) || ano % 400 == 0;
    dias_no_mes = dias[mes - 1] + (mes == 2 && bissexto);
    return dia >= 1 && dia <= dias_no_mes;
}

static int ler_pontuacao(float *pontuacao) {
    char linha[64];
    char *fim;
    size_t i;
    float valor;
    int resultado;

    for (;;) {
        resultado = ler_linha("Pontuacao (0 a 100): ", linha, sizeof(linha));
        if (resultado <= 0) {
            return resultado;
        }

        for (i = 0; linha[i] != '\0'; i++) {
            if (linha[i] == ',') {
                linha[i] = '.';
            }
        }

        errno = 0;
        valor = strtof(linha, &fim);
        while (isspace((unsigned char)*fim)) {
            fim++;
        }

        if (linha[0] != '\0' && *fim == '\0' && errno != ERANGE &&
            valor >= 0.0f && valor <= 100.0f) {
            *pontuacao = valor;
            return 1;
        }

        printf("Pontuacao invalida. Informe um valor de 0 a 100.\n");
    }
}

static void imprimir_cpf(const char cpf[12]) {
    printf("%.3s.%.3s.%.3s-%.2s", cpf, cpf + 3, cpf + 6, cpf + 9);
}

static void imprimir_candidato(const Candidato *candidato, size_t numero) {
    printf("%3zu | %-30s | %s | ", numero, candidato->nome, candidato->data_nascimento);
    imprimir_cpf(candidato->cpf);
    printf(" | %6.2f\n", candidato->pontuacao);
}

static void listar_candidatos(const Candidato candidatos[], size_t quantidade) {
    size_t i;
    size_t numero = 1;
    int encontrou_aprovado = 0;
    int encontrou_reprovado = 0;

    printf("\n=== CLASSIFICACAO DO CONCURSO ===\n");
    printf("Nota minima para aprovação: %.2f\n", NOTA_MINIMA_APROVACAO);
    printf(" Nº | Nome                           | Nascimento | CPF            | Nota\n");
    printf("----+--------------------------------+------------+----------------+-------\n");
    printf("APROVADOS\n");

    for (i = 0; i < quantidade; i++) {
        if (candidatos[i].pontuacao >= NOTA_MINIMA_APROVACAO) {
            imprimir_candidato(&candidatos[i], numero++);
            encontrou_aprovado = 1;
        }
    }
    if (!encontrou_aprovado) {
        printf("(nenhum candidato aprovado)\n");
    }

    printf("REPROVADOS\n");
    for (i = 0; i < quantidade; i++) {
        if (candidatos[i].pontuacao < NOTA_MINIMA_APROVACAO) {
            imprimir_candidato(&candidatos[i], numero++);
            encontrou_reprovado = 1;
        }
    }
    if (!encontrou_reprovado) {
        printf("(nenhum candidato reprovado)\n");
    }
}

static void cadastrar_candidato(Candidato candidatos[], size_t *quantidade) {
    Candidato novo;
    char entrada[128];
    int resultado;
    size_t i;

    if (*quantidade >= MAX_CANDIDATOS) {
        printf("Limite de candidatos atingido.\n");
        return;
    }

    resultado = ler_linha("Nome completo: ", novo.nome, sizeof(novo.nome));
    if (resultado <= 0) {
        return;
    }
    if (novo.nome[0] == '\0' || strchr(novo.nome, ';') != NULL) {
        printf("O nome nao pode ficar vazio nem conter ponto e virgula.\n");
        return;
    }

    resultado = ler_linha("Data de nascimento (DD/MM/AAAA): ",
                          novo.data_nascimento, sizeof(novo.data_nascimento));
    if (resultado <= 0) {
        return;
    }
    if (!data_valida(novo.data_nascimento)) {
        printf("Data invalida. Use uma data real no formato DD/MM/AAAA.\n");
        return;
    }

    resultado = ler_linha("CPF (11 numeros, com ou sem pontuacao): ",
                          entrada, sizeof(entrada));
    if (resultado <= 0) {
        return;
    }
    if (!normalizar_cpf(entrada, novo.cpf)) {
        printf("CPF invalido. Informe exatamente 11 numeros.\n");
        return;
    }
    for (i = 0; i < *quantidade; i++) {
        if (strcmp(candidatos[i].cpf, novo.cpf) == 0) {
            printf("Ja existe um candidato cadastrado com esse CPF.\n");
            return;
        }
    }

    resultado = ler_pontuacao(&novo.pontuacao);
    if (resultado <= 0) {
        return;
    }

    candidatos[(*quantidade)++] = novo;
    candidatos_ordenar(candidatos, *quantidade);

    {
        char erro[160];
        if (!salvar_candidatos(CAMINHO_DADOS, candidatos, *quantidade,
                               erro, sizeof(erro))) {
            for (i = 0; i < *quantidade; i++) {
                if (strcmp(candidatos[i].cpf, novo.cpf) == 0) {
                    size_t j;
                    for (j = i + 1; j < *quantidade; j++) {
                        candidatos[j - 1] = candidatos[j];
                    }
                    (*quantidade)--;
                    break;
                }
            }
            printf("Nao foi possivel salvar o cadastro: %s\n", erro);
            return;
        }
    }

    printf("Candidato cadastrado e classificacao atualizada.\n");
}

static void consultar_candidato(const Candidato candidatos[], size_t quantidade) {
    char entrada[32];
    char cpf[12];
    int resultado = ler_linha("CPF para consulta: ", entrada, sizeof(entrada));
    const Candidato *candidato;
    size_t i;

    if (resultado <= 0) {
        return;
    }
    if (!normalizar_cpf(entrada, cpf)) {
        printf("CPF invalido. Informe exatamente 11 numeros.\n");
        return;
    }

    candidato = candidato_buscar_cpf(candidatos, quantidade, cpf);
    if (candidato == NULL) {
        printf("Nenhum candidato encontrado com esse CPF.\n");
        return;
    }

    for (i = 0; i < quantidade; i++) {
        if (&candidatos[i] == candidato) {
            printf("\nPosicao: %zu\n", i + 1);
            printf("Situacao: %s\n",
                   candidato->pontuacao >= NOTA_MINIMA_APROVACAO
                       ? "APROVADO"
                       : "REPROVADO");
            imprimir_candidato(candidato, i + 1);
            return;
        }
    }
}

int main(void) {
    setlocale(LC_ALL,"Portuguese_Brazil.utf8");
    setlocale(LC_NUMERIC,"C");

    Candidato candidatos[MAX_CANDIDATOS];
    size_t quantidade = 0;
    char erro[160];
    int opcao;
    int resultado;

    if (!carregar_candidatos(CAMINHO_DADOS, candidatos, MAX_CANDIDATOS,
                             &quantidade, erro, sizeof(erro))) {
        fprintf(stderr, "Erro ao carregar candidatos: %s\n", erro);
        return EXIT_FAILURE;
    }
    candidatos_ordenar(candidatos, quantidade);

    printf("Cadastro e classificacao de concurso publico\n");
    printf("Candidatos carregados: %zu\n", quantidade);

    for (;;) {
        printf("\n1 - Listar classificacao\n");
        printf("2 - Cadastrar candidato\n");
        printf("3 - Consultar candidato pelo CPF\n");
        printf("0 - Sair\n");

        resultado = ler_opcao(&opcao);
        if (resultado == 0) {
            printf("\nEncerrando o programa.\n");
            break;
        }
        if (resultado < 0) {
            continue;
        }

        switch (opcao) {
            case 1:
                listar_candidatos(candidatos, quantidade);
                break;
            case 2:
                cadastrar_candidato(candidatos, &quantidade);
                break;
            case 3:
                consultar_candidato(candidatos, quantidade);
                break;
            case 0:
                printf("Encerrando o programa.\n");
                return EXIT_SUCCESS;
            default:
                printf("Opcao inexistente.\n");
        }
    }

    return EXIT_SUCCESS;
}
