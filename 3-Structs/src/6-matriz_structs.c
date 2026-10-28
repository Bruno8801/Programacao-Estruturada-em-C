#include <stdio.h>
#include <locale.h>
#include <string.h>
#include "Pessoa_struct.h"

void imprimirMatriz(struct Pessoa matriz[2][3], int linhas, int colunas) {
    printf("%-15s %-6s %-6s\n", "Nome", "Idade", "Peso");
    printf("-----------------------------------\n");
    for (int i = 0; i < linhas; i++) {
        for (int j = 0; j < colunas; j++) {
            printf("%-15s %-6d %-6.2f\n",
                matriz[i][j].nome,
                matriz[i][j].idade,
                matriz[i][j].peso);
        }
        printf("\n"); // separa cada linha
    }
}

int main(void) {
    setlocale(LC_ALL,"Portuguese_Brazil.utf8");
    struct Pessoa matrizPessoas[2][3];

    // linha 0
    strcpy(matrizPessoas[0][0].nome, "Maria");
    matrizPessoas[0][0].idade = 35;
    matrizPessoas[0][0].peso = 58.5;

    strcpy(matrizPessoas[0][1].nome, "Josefino");
    matrizPessoas[0][1].idade = 27;
    matrizPessoas[0][1].peso = 75.2;

    strcpy(matrizPessoas[0][2].nome, "Pedro");
    matrizPessoas[0][2].idade = 31;
    matrizPessoas[0][2].peso = 72.2;

    // linha 1
    strcpy(matrizPessoas[1][0].nome, "Antonieta");
    matrizPessoas[1][0].idade = 45;
    matrizPessoas[1][0].peso = 66.8;

    strcpy(matrizPessoas[1][1].nome, "Carlos");
    matrizPessoas[1][1].idade = 29;
    matrizPessoas[1][1].peso = 80.5;

    strcpy(matrizPessoas[1][2].nome, "Fernanda");
    matrizPessoas[1][2].idade = 33;
    matrizPessoas[1][2].peso = 60.3;

    // imprime só as 2 linhas preenchidas
    imprimirMatriz(matrizPessoas, 2, 3);

    return 0;
}
