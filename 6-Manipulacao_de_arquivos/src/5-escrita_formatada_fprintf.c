#include <stdio.h>

int main(void) {
    FILE *arquivo;
    int idade = 31;
    float peso = 72;
    char nome[50] = "Bruno Silva";

    arquivo = fopen("../data/arq_fprintf.txt", "w");

    if (arquivo != NULL) {
        fprintf(arquivo, "Idade: %d\n", idade);
        fprintf(arquivo, "Peso: %.2f\n", peso);
        fprintf(arquivo, "Nome: %s\n", nome);

        fclose(arquivo);
        printf("Todos os dados foram formatados e inseridos no arquivo corretamente!\n");
    } else {
        printf("Erro ao abrir o arquivo.\n");
    }
    return 0;
}