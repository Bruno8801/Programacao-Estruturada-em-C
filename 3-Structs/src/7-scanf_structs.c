#include <stdio.h>
#include <locale.h>

struct Pessoa {
    char nome[50];
    int idade;
};

int main(void) {
    setlocale(LC_ALL,"Portuguese_Brazil.utf8");
    struct Pessoa candidatos[5];

    // leitura de dados
    for (int i = 0; i < 5; i++) {
        printf("Digite o nome do %i° candidato: ", i + 1);
        // IMPORTANTE: Arrays em C "decaem" automaticamente para ponteiros
        // candidatos[i].nome é um array char[50], então já é um endereço
        // Não precisa do & aqui!
        scanf("%s", candidatos[i].nome);

        printf("Digite a idade do %i° candidato: ", i + 1);
        // candidatos[i].idade é um int simples (não é array)
        // scanf precisa do ENDEREÇO (&) para saber onde guardar o valor lido
        scanf("%i", &candidatos[i].idade);
    }

    for (int i = 0; i < 5; i++) {
        printf("\n%i° Candidato\nNome: %s\nIdade: %i\n", i + 1,candidatos[i].nome, candidatos[i].idade);
    }

    return 0;
}