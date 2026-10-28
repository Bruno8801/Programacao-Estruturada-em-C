#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

int main(void) {
    setlocale(LC_ALL,"Portuguese_Brazil.utf8");
    // Mantém o ponto como separador decimal para a leitura de números.
    setlocale(LC_NUMERIC, "C");
    
    int n;
    printf("Quantas notas deseja registrar?: ");
    scanf("%d", &n);

    float *notas = (float *)malloc(n * sizeof(float)); 
    float soma = 0; 
    float media = 0; 
 
    for (int i = 0; i < n; i++) { 
        printf("Digite a nota %d: ", i + 1); 
        scanf("%f", &notas[i]); 
        soma += *(notas + i); 
    } 
 
    media = soma / n; 
    printf("Média das notas: %.2f\n", media); 
 
    free(notas);

    return 0;
}