#include <stdio.h>
#include <locale.h>
#include <stdlib.h>

int main(void) {
    setlocale(LC_ALL, "Portuguese_Brazil.utf8");
    printf("Verificando se os números de 0 a 100 são pares ou impares\n");

    int x =0; // usado no laço while
    int y =101; // usado no laço for

    while (x >=0 && x <= 100) // laço while
    {
        if (x % 2 == 0)
        {
            printf("O número %i é par\n", x);
        } else {
            printf("O número %i impar\n", x);
        }
        x++;
    }

    printf("----------------------------\n");
    
    for (y; y <= 200; y++) {
        if (y % 2 == 0)
        {
            printf("O número %i é par\n", y);
        } else {
            printf("O número %i impar\n", y);
        }
    }
    return 0;
}