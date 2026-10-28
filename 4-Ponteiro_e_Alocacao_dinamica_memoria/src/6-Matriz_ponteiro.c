#include <stdio.h>

int main(void) {
    int matriz[3][3] = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    };

    int *ponteiro = NULL; // Declaração de ponteiro para percorrer a matriz
    ponteiro = &matriz[0][0]; // Inicialização de ponteiro

    // imprimir a matriz pelo ponteiro
    printf("Matriz impressa pelo ponteiro:\n");
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            printf("%d ", *ponteiro); // Acessando elementos da matriz do ponteiro
            ponteiro++; // Avançando para o próximo elemento
        }
        printf("\n");
    }

    return 0;

}