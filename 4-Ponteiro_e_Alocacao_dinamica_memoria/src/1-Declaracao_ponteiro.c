#include <stdio.h>
#include <locale.h>

int main(void) {
    setlocale(LC_ALL,"Portuguese_Brazil.utf8");
    // criando ponteiros usando * para indicar sua função
    int *ponteiro_inteiro;
    float *ponteiro_real;
    char *ponteiro_caractere;

    // inicializando o ponteiro com atribuição de um endereço de memória com o operador &
    int x = 10;
    float y = 12.558;
    char z = 'M';

    ponteiro_inteiro = &x; // Agora a variável 'x' possui um ponteiro que aponta para seu endereço na memória
    ponteiro_real = &y;
    ponteiro_caractere = &z;

    printf("Valores das variáveis: int: %d, float: %.2f, char: %c\n", *ponteiro_inteiro, *ponteiro_real, *ponteiro_caractere);
    printf("\nEndereços das variáveis:\nint: %p\nfloat: %p\nchar: %p\n", (void*)&x, (void*)&y, (void*)&z);
    printf("\nEndereços guardados nos ponteiros:\nint: %p\nfloat: %p\nchar: %p\n", (void*)ponteiro_inteiro, (void*)ponteiro_real, (void*)ponteiro_caractere);

    return 0;
}