#include <stdio.h>
#include <stdlib.h>
#include <errno.h>  // Permite detectar erros de conversao, como valores fora do limite de long.
#include <limits.h> // Define os limites de tipos inteiros, como INT_MIN e INT_MAX.
#include <string.h>

// Converte um texto para int e retorna 1 se ele inteiro for valido; caso contrario, retorna 0.
static int converter_inteiro(const char *texto, int *numero) {
    char *fim;
    long valor;

    // strtol permite verificar onde a conversao parou; errno sinaliza estouro de long.
    errno = 0;
    valor = strtol(texto, &fim, 10);

    // Rejeita texto sem numero e valores que nao cabem em long ou int.
    if (texto == fim || errno == ERANGE || valor < INT_MIN || valor > INT_MAX) {
        return 0;
    }

    // Aceita espacos no final, incluindo tab, CR e LF; rejeita outros caracteres.
    while (*fim == ' ' || *fim == '\t' || *fim == '\r' || *fim == '\n') {
        fim++;
    }
    if (*fim != '\0') {
        return 0;
    }

    *numero = (int)valor;
    return 1;
}

// Usa o argumento recebido ou solicita entradas ate receber um numero inteiro valido.
static int ler_inteiro(const char *mensagem, const char *argumento, int *numero) {
    char linha[128];

    if (argumento != NULL) {
        if (converter_inteiro(argumento, numero)) {
            return 1;
        }
        printf("Erro: \"%s\" nao e um numero inteiro valido. Digite novamente.\n",
               argumento);
    }

    for (;;) {
        printf("%s", mensagem);
        // fgets limita a leitura ao tamanho do vetor e evita ultrapassar seus limites.
        if (fgets(linha, sizeof(linha), stdin) == NULL) {
            fprintf(stderr, "\nErro: nao foi possivel ler a entrada.\n");
            return 0;
        }

        // Se nao coube a linha toda, descarta o restante para nao contaminar a proxima leitura.
        if (strchr(linha, '\n') == NULL && !feof(stdin)) {
            int caractere;
            while ((caractere = getchar()) != '\n' && caractere != EOF) {
            }
            printf("Erro: entrada muito longa. Digite um numero inteiro.\n");
            continue;
        }

        if (converter_inteiro(linha, numero)) {
            return 1;
        }
        printf("Erro: entrada invalida. Digite um numero inteiro.\n");
    }
}

int main(int argc, char *argv[]) {
    int num1;
    int num2;
    int soma;
    // argc conta os argumentos; argv[0] e o nome do programa, argv[1] e argv[2] sao os valores.
    const char *argumento1 = argc > 1 ? argv[1] : NULL;
    const char *argumento2 = argc > 2 ? argv[2] : NULL;

    // Argumentos sao opcionais, mas se forem usados, devem ser no maximo dois.
    if (argc > 3) {
        printf("Uso: %s [num1 num2]\n", argv[0]);
        return EXIT_FAILURE;
    }

    if (!ler_inteiro("Digite o primeiro numero inteiro: ", argumento1, &num1) ||
        !ler_inteiro("Digite o segundo numero inteiro: ", argumento2, &num2)) {
        return EXIT_FAILURE;
    }

    // Verifica antes da soma para evitar estouro, que causaria um resultado incorreto.
    if ((num2 > 0 && num1 > INT_MAX - num2) ||
        (num2 < 0 && num1 < INT_MIN - num2)) {
        fprintf(stderr, "Erro: a soma excede o limite dos numeros inteiros.\n");
        return EXIT_FAILURE;
    }

    soma = num1 + num2;
    printf("A soma de %d e %d = %d\n", num1, num2, soma);
    return 0;
}