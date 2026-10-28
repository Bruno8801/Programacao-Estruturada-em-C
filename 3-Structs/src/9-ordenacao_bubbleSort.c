#include <stdio.h>
#include <locale.h>
#include <string.h>

struct Pessoa {
    char nome[50];
    int idade;
};

void bubbleSort(struct Pessoa *candidatos, int tam) {
    for (int i = 0; i < tam - 1; i++) {
        for (int j = 0; j < tam - i - 1; j++) {
            if (candidatos[j].idade > candidatos[j + 1].idade) {
                struct Pessoa aux = candidatos[j];
                candidatos[j] = candidatos[j + 1];
                candidatos[j + 1] = aux;
            }
        }
    }
};

int main(void) {
    setlocale(LC_ALL,"Portuguese_Brazil.utf8");
    struct Pessoa candidatos[3];

    // leitura de dados
    for (int i = 0; i < 3; i++) {
        printf("Digite o nome do %i° candidato: ", i + 1);
        scanf("%s", candidatos[i].nome);

        printf("Digite a idade do %i° candidato: ", i + 1);
        scanf("%i", &candidatos[i].idade);
    }

    // ordenando vetores por idade
    bubbleSort(candidatos, 3);

    // imprimindo dados ordenados
    printf("\nCandidatos em ordem de idade crescente: \n");
    for (int i = 0; i < 3; i++) {
        printf("\nCandidato %i\nNome: %s\nIdade: %i\n", i + 1, candidatos[i].nome, candidatos[i].idade);
    }

    return 0;
}