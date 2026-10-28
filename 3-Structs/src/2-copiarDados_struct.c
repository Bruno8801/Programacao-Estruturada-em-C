#include <stdio.h>
#include <string.h>
#include "Pessoa_struct.h"

int main(void) {
    struct Pessoa p1, p2;
        strcpy(p1.nome, "Chespirito");
        p1.idade = 48;
        p1.peso = 71.563;

    printf("Nome: %s\nidade: %i\npeso: %.2f\n", p1.nome, p1.idade, p1.peso);
    
    printf("Pessoa 'p1' agora tem copia de Pessoa 'p2'\n");
    memcpy(&p2, &p1, sizeof(struct Pessoa));
    printf("Nome: %s\nidade: %i\npeso: %.2f", p2.nome, p2.idade, p2.peso);
    
    return 0;
}
