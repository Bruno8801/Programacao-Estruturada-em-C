#include <stdio.h>
#include <locale.h>
#include <string.h>

struct Pessoa {
    char nome[50];
    int idade;
};

int main(void) {
    setlocale(LC_ALL,"Portuguese_Brazil.utf8");
    struct Pessoa candidatos[2];

    // leitura de dados
    for (int i = 0; i < 2; i++) {
        printf("Digite o nome do %i° candidato: ", i + 1);
        scanf("%s", candidatos[i].nome);

        printf("Digite a idade do %i° candidato: ", i + 1);
        scanf("%i", &candidatos[i].idade);
    }

    // buscar dados
    char nomeBusca[50];
    printf("Digite o nome para buscar na lista: ");
    scanf("%s", nomeBusca);

    // buscar dado no vetor
    int posicaoEncontrada = -1;
    for (int i = 0; i < 2; i++) {
        if (strcmp(candidatos[i].nome, nomeBusca) == 0) {
            posicaoEncontrada = i;
            break;  // encontrou, sai do loop
        }
    }

    // exibir resultados da busca
    if (posicaoEncontrada != -1) {
        printf("\nPessoa encontrada na posição %i\n", posicaoEncontrada + 1);
        printf("Nome: %s\nIdade: %i\n", candidatos[posicaoEncontrada].nome, candidatos[posicaoEncontrada].idade);
    } else {
        printf("\nPessoa não encontrada.\n");
    }

    return 0;
}