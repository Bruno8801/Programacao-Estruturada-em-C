#include <stdio.h>
#include <locale.h>

int main(void) {
    setlocale(LC_ALL,"Portuguese_Brazil.utf8");

    int valor = 10;
    int *ponteiro = &valor; // Ponteiro para o valor
    int **ponteiro_para_ponteiro = &ponteiro; // Ponteiro para o ponteiro

    // Acessando o valor através do ponteiro para ponteiro
    printf("Valor acessado através do ponteiro para ponteiro: %d\n", **ponteiro_para_ponteiro);

    // Modificando o valor através do ponteiro para ponteiro
    **ponteiro_para_ponteiro = 20;
    printf("Novo valor após modificação: %d\n", valor);

    return 0;
}