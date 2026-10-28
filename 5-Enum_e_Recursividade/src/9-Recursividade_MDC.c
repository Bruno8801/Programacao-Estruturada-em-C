#include <stdio.h>
#include <locale.h>

unsigned int mdc(unsigned int a, unsigned int b) {
    if (b == 0) // condição de parada
        return a;
    else
        return mdc(b, a % b);
}

int main(void) {
    setlocale(LC_ALL,"Portuguese_Brazil.utf8");

    unsigned int numero1 = 48, numero2 = 18;
    printf("O MDC de %u e %u é: %u\n", numero1, numero2, mdc(numero1, numero2));

    return 0;
}