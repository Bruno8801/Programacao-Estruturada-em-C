#include <stdio.h>
#include <locale.h>

unsigned int fibonacci(unsigned int n) {
    if (n <= 1) // parada do loop
        return n;
    else
        return fibonacci(n - 1) + fibonacci(n - 2); // chamada recursiva
}
int main(void) {
    setlocale(LC_ALL,"Portuguese_Brazil.utf8");
    unsigned int termo = 10;

    printf("Os primeiros %u termos da sequência de Fibonacci são:\n", termo);
    for (unsigned int i = 0; i < termo; i++) {
        printf("%u ", fibonacci(i));
    }
    printf("\n");

    return 0;
}