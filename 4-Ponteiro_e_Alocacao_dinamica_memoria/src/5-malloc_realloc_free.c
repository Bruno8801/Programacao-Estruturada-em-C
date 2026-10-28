#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

int main(void) {
    setlocale(LC_ALL,"Portuguese_Brazil.utf8");

    // Alocação dinâmica de memória para um inteiro
    int n;
    printf("Digite um número inicial de elementos do vetor: ");
    scanf("%d", &n);

    int *vetor = malloc(n * sizeof(int)); // Aloca memória para n inteiros
    if (vetor == NULL) { // verificando se a alocação foi bem-sucedida
        printf("Erro na alocação de memória.\n");
        return 1; // Sai do programa com erro
    } else {
        printf("Memória alocada com sucesso para %d elementos.\n", n);
    }

    // Redimensionar o vetor se necessário
    if (n < 100) {
        printf("Redimensionando o vetor para 100 elementos.\n");
        int *novo_vetor = realloc(vetor, 100 * sizeof(int)); // Redimensiona para 100 inteiros
        if (novo_vetor == NULL) { // verificando se a realocação foi bem-sucedida
            printf("Erro na realocação de memória.\n");
            free(vetor); // Libera a memória previamente alocada
            return 1; // Sai do programa com erro
        } else {
            printf("Memória realocada com sucesso para 100 elementos.\n");
        }
        vetor = novo_vetor; // Atualiza o ponteiro para o novo vetor
    }
    free(vetor); // Libera a memória alocada
    printf("Memória liberada com sucesso.\n");
    
    return 0; // Sai do programa com sucesso
}