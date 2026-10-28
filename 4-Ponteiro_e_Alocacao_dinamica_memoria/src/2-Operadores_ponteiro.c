#include <stdio.h>
#include <locale.h>

int main(void) {
    setlocale(LC_ALL,"Portuguese_Brazil.utf8");

    int x = 20;
    int *ponteiro_inteiro = &x; // Operador de endereço &

    int valor_de_x = *ponteiro_inteiro; // Acessando pelo ponteiro

    *ponteiro_inteiro = 10; // Modificando o valor da variável pelo ponteiro

    typedef struct { // Acessando um membro da estrutura através de um ponteiro
        int valor;
    } Estrutura;
    Estrutura s;
    Estrutura *ponteiro_para_s = &s; // Ponteiro para a estrutura utilizando o operador de desreferência *
    
    ponteiro_para_s -> valor = 10; // Acessando o membro da estrutura através do ponteiro utilizando o operador ->

    return 0;
}