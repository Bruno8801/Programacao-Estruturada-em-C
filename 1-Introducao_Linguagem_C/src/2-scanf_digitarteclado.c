#include <stdio.h>
#include <locale.h>
#include <string.h>

int main(void) {
    setlocale(LC_ALL, "Portuguese_Brazil.utf8");
    printf("Olá tudo bem?\n");

    int idade;
    // Ponteiro para uma string constante nos blocos if.
    const char *res;
    char nome[100];
    printf("Digite seu nome: ");

    // fgets lê uma linha inteira e permite espaços, como em "Maria Antonieta de Las Nieves".
    // sizeof(nome) limita a leitura ao tamanho disponível no vetor.
    fgets(nome, sizeof(nome), stdin);

    // fgets normalmente armazena o Enter como '\n'; esta linha o remove.
    // strcspn pertence a string.h e encontra a posição do primeiro '\n' e depois o remove.
    nome[strcspn(nome, "\n")] = '\0';

    printf("Digite sua idade: ");
    // scanf adequado para ler um número inteiro ou qualquer outro dado que não possua espaços.
    scanf("%i", &idade);

    if (idade >= 18 && idade < 60) {
        res = "você é maior de idade.";
    } else if (idade < 18) {
        res = "você é menor de idade.";
    } else {
        res = "você é idoso.";
    }
    printf("Olá, %s! Sua idade é: %i anos, e %s", nome, idade, res);
    
    return 0;
}