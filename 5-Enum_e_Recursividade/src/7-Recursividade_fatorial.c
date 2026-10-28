#include <stdio.h>
#include <locale.h>

unsigned int fatorial(unsigned int n) {
    if (n == 0) // condição de parada do loop
        return 1;
    else
        return n * fatorial(n - 1); // chamada recursiva
}
int main(void) {
    setlocale(LC_ALL,"Portuguese_Brazil.utf8");
    unsigned int numero = 5;
    unsigned int resultado = fatorial(numero);

    printf("O fatorial de %u é: %u", numero, resultado);
    return 0;
}