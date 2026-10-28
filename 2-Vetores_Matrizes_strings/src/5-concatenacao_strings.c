#include <stdio.h>
#include <locale.h>
#include <string.h>

int main(void) {
    setlocale(LC_ALL,"Portuguese_Brazil.utf8");
    char nome[20];
    char sobre_nome[50];

    printf("Digite seu nome: ");
    fgets(nome, sizeof(nome), stdin);
    nome[strcspn(nome, "\n")] = 0; // Remove o caractere de nova linha

    printf("Digite seu sobre-nome: ");
    fgets(sobre_nome, sizeof(sobre_nome), stdin);
    sobre_nome[strcspn(sobre_nome, "\n")] = 0;

    strcat(nome, " ");
    strcat(nome, sobre_nome);

    printf("Nome completo: %s\n", nome);

    return 0;
}