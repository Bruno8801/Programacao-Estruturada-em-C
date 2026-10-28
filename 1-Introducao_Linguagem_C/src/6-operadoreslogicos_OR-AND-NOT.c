#include <stdio.h>
#include <locale.h>
#include <stdlib.h>

int main(void) {
    setlocale(LC_ALL, "Portuguese_Brazil.utf8");
    printf("Operadores Lógicos em C\n");
    printf("OR: ||\n"); // apenas um dos operadores lógicos precisa ser verdadeiro para que o resultado seja verdadeiro
    printf("AND: &&\n"); // todos operadores lógicos precisam ser verdadeiros para que o resultado seja verdadeiro
    printf("NOT: !\n"); // inverte o valor lógico, se for verdadeiro passa a ser falso e vice-versa

    int x;
    printf("Vamos verificar se um número é par ou ímpar?\n");
    printf("Digite um número: ");
    scanf("%i", &x);

    if (x % 2 == 0) { // operador lógico AND
        printf("O número %i é par.\n", x);
    } else { // operador lógico NOT
        printf("O número %i é ímpar.\n", x);
    }

    printf("Vamos verificar se um número é esta dentro do intervalo [1, 10]?\n");
    printf("Digite um número: ");
    scanf("%i", &x);

    // operador lógico AND
    if (x >= 1 && x <= 10) {
        printf("O número %i está dentro do intervalo [1, 10].\n", x);
    } else { // operador lógico NOT
        printf("O número %i não está dentro do intervalo [1, 10].\n", x);
    }

    printf("Vamos verificar se um número está fora do intervalo [1, 10]?\n");
    printf("Digite um número: ");
    scanf("%i", &x);

    // operador lógico OR
    if (x < 1 || x > 10) {
        printf("O número %i está fora do intervalo [1, 10].\n", x);
    } else { // operador lógico NOT
        printf("O número %i está dentro do intervalo [1, 10].\n", x);
    }
    
    return 0;
}