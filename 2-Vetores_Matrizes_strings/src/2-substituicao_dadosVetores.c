#include <stdio.h>
#include <locale.h>

int main(void) {
    setlocale(LC_ALL, "Portuguese_Brazil.utf8");
    printf("Substituindo dados em um vetor\n");

    printf("---Vetor original---\n");
    int numeros[10];
    int indice, novoValor;
    for (int i = 0; i < 10; i++) {
        numeros[i] = i + 1;
        printf("%d ", numeros[i]);
    }
    
    printf("\nDigite o índice do elemento a ser modificado: ");
    scanf("%d", &indice);
    printf("Digite o novo valor: ");
    scanf("%d", &novoValor);
    numeros[indice] = novoValor;

    printf("\nO valor do elemento do índice %d foi modificado para %d\n", indice, novoValor);

    printf("---Vetor modificado---\n");
    for (int i = 0; i < 10; i++) {
        printf("%d ", numeros[i]);
    }
    printf("\n");

    return 0;
}
