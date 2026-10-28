#include "arquivo.h"

#include <errno.h>
#include <stdio.h>
#include <string.h>

static void definir_erro(char *erro, size_t tamanho_erro, const char *mensagem) {
    if (tamanho_erro > 0) {
        snprintf(erro, tamanho_erro, "%s", mensagem);
    }
}

int carregar_candidatos(const char *caminho, Candidato candidatos[],
                        size_t capacidade, size_t *quantidade,
                        char *erro, size_t tamanho_erro) {
    FILE *arquivo = fopen(caminho, "r");
    char linha[256];
    size_t numero_linha = 0;

    *quantidade = 0;
    if (arquivo == NULL) {
        if (errno == ENOENT) {
            return 1;
        }
        snprintf(erro, tamanho_erro, "nao foi possivel abrir '%s'", caminho);
        return 0;
    }

    while (fgets(linha, sizeof(linha), arquivo) != NULL) {
        Candidato candidato;
        char extra;
        size_t tamanho;

        numero_linha++;
        tamanho = strlen(linha);
        if (tamanho > 0 && linha[tamanho - 1] == '\n') {
            linha[--tamanho] = '\0';
        }
        if (tamanho > 0 && linha[tamanho - 1] == '\r') {
            linha[--tamanho] = '\0';
        }
        if (linha[0] == '\0') {
            continue;
        }

        if (*quantidade >= capacidade) {
            fclose(arquivo);
            snprintf(erro, tamanho_erro, "limite de %zu candidatos excedido",
                     capacidade);
            return 0;
        }

        if (sscanf(linha, "%99[^;];%10[^;];%11[^;];%f%c",
                   candidato.nome, candidato.data_nascimento,
                   candidato.cpf, &candidato.pontuacao, &extra) != 4 ||
            strchr(candidato.nome, '\n') != NULL ||
            strlen(candidato.cpf) != 11 ||
            candidato.pontuacao < 0.0f || candidato.pontuacao > 100.0f) {
            fclose(arquivo);
            snprintf(erro, tamanho_erro, "formato invalido na linha %zu do arquivo",
                     numero_linha);
            return 0;
        }

        candidatos[(*quantidade)++] = candidato;
    }

    if (ferror(arquivo)) {
        fclose(arquivo);
        definir_erro(erro, tamanho_erro, "erro ao ler o arquivo de candidatos");
        return 0;
    }

    fclose(arquivo);
    return 1;
}

int salvar_candidatos(const char *caminho, const Candidato candidatos[],
                      size_t quantidade, char *erro, size_t tamanho_erro) {
    FILE *arquivo = fopen(caminho, "w");
    size_t i;

    if (arquivo == NULL) {
        snprintf(erro, tamanho_erro, "nao foi possivel gravar '%s'", caminho);
        return 0;
    }

    for (i = 0; i < quantidade; i++) {
        if (fprintf(arquivo, "%s;%s;%s;%.2f\n",
                    candidatos[i].nome, candidatos[i].data_nascimento,
                    candidatos[i].cpf, candidatos[i].pontuacao) < 0) {
            fclose(arquivo);
            definir_erro(erro, tamanho_erro, "erro ao escrever candidatos");
            return 0;
        }
    }

    if (fclose(arquivo) != 0) {
        definir_erro(erro, tamanho_erro, "erro ao finalizar o arquivo de candidatos");
        return 0;
    }

    return 1;
}
