#include <stdio.h>
#include <string.h>
#include <locale.h>

int main(void) {
    setlocale(LC_ALL,"Portuguese_Brazil.utf8");
    // Mantém o ponto como separador decimal para a leitura de números.
    setlocale(LC_NUMERIC, "C");

    struct Pessoa {
        char nome[50];
        int idade;
        float altura;
    };

    int n;
    printf("Quantas Pessoas deseja cadastrar?: ");
    scanf("%d", &n);
    printf("\n");

    // Remove o Enter deixado pelo scanf antes do primeiro fgets.
    while (getchar() != '\n');

    struct Pessoa pessoas[n];

    for (int i = 0; i < n; i++) {
        printf("Digite o nome da pessoa %d: ", i + 1);
        // fgets permite ler nomes com espaços, como "Ana Clara".
        fgets(pessoas[i].nome, sizeof(pessoas[i].nome), stdin);
        // Remove o '\n' que o fgets armazena no final do texto.
        pessoas[i].nome[strcspn(pessoas[i].nome, "\n")] = '\0';
        printf("Digite a idade da pessoa %d: ", i + 1);
        scanf("%d", &pessoas[i].idade);
        printf("Digite a altura da pessoa %d: ", i + 1);
        scanf("%f", &pessoas[i].altura);

        // Descarta o Enter deixado pelo scanf antes do próximo fgets.
        while (getchar() != '\n');
    }

    // Criando ponteiros para as estruturas
    struct Pessoa *ponteiros[n];
    for (int i = 0; i < n; i++) {
        ponteiros[i] = &pessoas[i];
    }

    // Imprimindo os dados das pessoas usando o ponteiro
    for (int i = 0; i < n; i++) {
        printf("\nDados da %i° pessoa:\n", i + 1);
        printf("Nome: %s\n", ponteiros[i]->nome);
        printf("Idade: %d\n", ponteiros[i]->idade);
        printf("Altura: %.2f\n", ponteiros[i]->altura);
    }

    return 0;
}