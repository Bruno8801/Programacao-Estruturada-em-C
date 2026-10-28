#include <stdio.h>
#include <locale.h>

union numero {
    int inteiro;
    float flutuante;
};

int main(void) {
    setlocale(LC_ALL,"Portuguese_Brazil.utf8");
    union numero num;

    num.inteiro = 10;
    
    printf("Valor inteiro: %d", num.inteiro);

    num.flutuante = 3.25;

    printf("\nValor de ponto flutuante: %.2f\n",num.flutuante);

    printf("\nEndereço das variáveis:\nInteiro: %p\nFlutuante: %p", (void *)&num.inteiro, (void *)&num.flutuante);

    return 0;
}