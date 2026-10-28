#include <stdio.h>
#include <locale.h>
#include <stdlib.h>

int main(void) {
    setlocale(LC_ALL, "Portuguese_Brazil.utf8");
    // Código para o switch case

    int a, b;
    double resp;
    char op;

    printf("Selecione uma operação matemática entre (+, -, *, /): ");
    scanf(" %c", &op); // ⚠️ O espaço antes do %c é para ignorar qualquer caractere de nova linha que possa estar no buffer, usa-se quando é solicitado um character (char) com scanf.
    printf("Digite o primeiro número: ");
    scanf("%i", &a);
    printf("Digite o segundo número: ");
    scanf("%i", &b);

    switch (op)
    {
    case '+':
        resp = a + b;
        printf("Você selecionou a soma e o resultado foi: %.2f", resp);
        break;
    case '-':
        resp = a - b;
        printf("Você selecionou a subtração e o resultado foi: %.2f", resp);
        break;
    case '*':
        resp = a * b;
        printf("Você selecionou a multiplicação e o resultado foi: %.2f", resp);
        break;
    case '/':
        if (b == 0) {
            printf("Não é possível dividir por zero.");
            break;
        }
        resp = (double) a / b; // convertendo int para float/double
        printf("Você selecionou a divisão e o resultado foi: %.2f", resp);
        break;

    default:
        printf("Operação inválida.");
    }

    return 0;
}