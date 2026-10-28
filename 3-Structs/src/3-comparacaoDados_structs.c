#include <stdio.h>
#include <string.h>
#include <locale.h>
#include "Pessoa_struct.h"

int main(void) {
    setlocale(LC_ALL,"Portuguese_Brazil.utf8");
    struct Pessoa p1, p2;
        strcpy(p1.nome, "Bruno Silva");
        p1.idade = 31;
        p1.peso = 71.200;

        strcpy(p2.nome, "Rafael Lorenzo");
        p2.idade = 28;
        p2.peso = 68;
    
    // comparando dados nas structs
    int comparacao = strcmp(p1.nome, p2.nome);
    if (comparacao == 0) {
        printf("Os nome são iguais.\n");
    } else {
        printf("Os nome são diferentes.\n");
    }

    return 0;
}