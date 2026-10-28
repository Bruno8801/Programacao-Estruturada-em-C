#include <stdio.h>
#include <locale.h>

int main(void) {
    setlocale(LC_ALL,"Portuguese_Brazil.utf8");

    int array[5] = {1, 2, 3, 4, 5};
    int *ponteiro_primeiro = &array[0]; // Ponteiro para o primeiro elemento do array
    int *ponteiro_ultimo = &array[4]; // Ponteiro para o último elemento do array

    // Adição
    printf("Valor do elemento acessado pelo primeiro ponteiro: %d\n", *ponteiro_primeiro);
    ponteiro_primeiro++; // Avança para o próximo elemento do array
    printf("Valor do elemento acessado pelo primeiro ponteiro após incremento: %d\n", *ponteiro_primeiro);

    // Subtração
    printf("Valor do elemento acessado pelo último ponteiro: %d\n", *ponteiro_ultimo);
    ponteiro_ultimo--; // Retrocede para o elemento anterior do array
    printf("Valor do elemento acessado pelo último ponteiro após decremento: %d\n", *ponteiro_ultimo);

    // Comparação
    if (ponteiro_primeiro == ponteiro_ultimo) {
        printf("Os ponteiros apontam para o mesmo elemento.\n");
    } else {
        printf("Os ponteiros apontam para elementos diferentes.\n");
    }

    return 0;
}