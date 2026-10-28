#include <stdio.h> // biblioteca padrão do C, que contém funções de entrada e saída, como printf e scanf
#include <locale.h> // ativa o UTF-8 no terminal
#include <stdlib.h> // biblioteca padrão do C, que contém funções de alocação de memória, controle de processos, conversões e outras

int main(void) { // função principal do programa, onde o código é executado
    setlocale(LC_ALL,"Portuguese_Brazil.utf8"); // serve para deixar o terminal em português do Brasil
    printf("Olá, Mundo!\n"); // agora acentos e caracteres especiais funcionam no terminal
    
    return 0; // o return 0; serve para indicar que o programa terminou com sucesso
}