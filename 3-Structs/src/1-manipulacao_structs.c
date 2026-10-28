#include <stdio.h>
#include <string.h>
#include "../include/Pessoa_struct.h" // caminho exato do include dentro de uma pasta externa a do projeto, use ../nome da pasta/nome do arquivo

int main(void) {
    struct Pessoa p1;
    strcpy(p1.nome, "Maria Antonieta");
    p1.idade = 71;
    p1.peso = 59.528;
    
    printf("Nome: %s, idade: %i, peso: %.2f", p1.nome, p1.idade, p1.peso);
    printf("\n---ENDERECO---\n");

    struct Endereco e1;
    strcpy(e1.rua, "Governador Luiz Ribeiro");
    e1.numero = 158;
    strcpy(e1.cep, "38.035-100");
    strcpy(e1.cidade, "Recife");
    strcpy(e1.estado, "Pernambuco");

    printf("Rua: %s, numero: %i, cep: %s, cidade: %s, estado: %s", e1.rua, e1.numero, e1.cep, e1.cidade, e1.estado);

    return 0;
}