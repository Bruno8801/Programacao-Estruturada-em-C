#include <stdio.h>

int main(void) {
    int matriz[3][3] = {
        {1, 2, 3},
        {4, 5, 6}, // elemento acessado (valor 4)
        {7, 8, 9}
    };
    int elemento = matriz[1][0]; // Acessa um elemento na linha 1, coluna 0
    // modificando um elemento na matriz
    matriz[1][1] = 10; // o elemento na posição da linha 1, coluna 1 (valor 5), agora vale 10

    // imprimindo a matriz
    printf("Matriz 3x3:\n");
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            printf("%d | ", matriz[i][j]);
        }
        printf("\n");
    }

    /* Operações em matrizes*/
    int matrizA[2][2] = {
        {1, 2},
        {3, 4}
    };
    int matrizB[2][2] = {
        {5, 6},
        {7, 8}
    };
    int matrizC[2][2];

    // imprimindo a matriz
    printf("Operação em Matrizes:\n");
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 2; j++) {
            matrizC[i][j] = matrizA[i][j] + matrizB[i][j]; // soma das matrizes
            printf("%d | ", matrizC[i][j]);
        }
        printf("\n");
    }

    return 0;
}