#include <stdio.h>
#include <locale.h>

int main(void) {
    setlocale(LC_ALL, "Portuguese_Brazil.utf8");
    printf("Criando vetores na linguagem C\n");

    // Vetor com cinco posições, indexadas de 0 a 4.
    int numeros[5] = {1, 2, 3, 4, 5};
    for (int i = 0; i < 5; i++) {
        printf("%d ", numeros[i]);
    }

    printf("\nImprimindo os números pares de 0 a 100\n");

    // 101 posições permitem armazenar os valores de 0 até 100.
    int blocoNumeros[101];
    for (int i = 0; i < 101; i++) {
        blocoNumeros[i] = i;

        // O resto da divisão por 2 é zero apenas para números pares.
        if (blocoNumeros[i] % 2 == 0) {
            printf("%d ", blocoNumeros[i]);
        }
    }

    printf("\n");
    return 0;
}