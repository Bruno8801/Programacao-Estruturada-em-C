#include <stdio.h>
#include <locale.h>
#include <string.h>
#include "Pessoa_struct.h"

int main(void) {
    setlocale(LC_ALL,"Portuguese_Brazil.utf8");
    struct Pessoa pessoas[100] = {
        {"Maria", 35, 58.500}, // essa é a Pessoa [0] do vetor pessoas[100]
        {"João", 27, 75.200}, // essa é a Pessoa [1] do vetor pessoas[100]
        {"Pedro", 31, 72.200} // e assim sucessivamente
    };

    void imprimirPessoa(struct Pessoa p) {
        printf("\nNome: %s\n", p.nome); 
        printf("Idade: %d\n", p.idade);
        printf("Peso: %.2f\n", p.peso); 
    };

    imprimirPessoa(pessoas[0]);
    imprimirPessoa(pessoas[1]);
    imprimirPessoa(pessoas[2]);

    return 0;
}