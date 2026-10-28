#include <stdio.h>
#include <string.h>
#include <locale.h>
#include "../include/Pessoa_struct.h"

void imprimirPessoa(struct Pessoa p) {
    printf("\nNome: %s\n", p.nome);
    printf("Idade: %d\n", p.idade);
    printf("Peso: %.2f\n", p.peso);
    printf("Endereço: %s\nNº: %d\n", p.endereco.rua, p.endereco.numero);
    printf("CEP: %s\n", p.endereco.cep);
    printf("Cidade: %s - Estado: %s\n", p.endereco.cidade, p.endereco.estado);
}

int main(void) {
    setlocale(LC_ALL,"Portuguese_Brazil.utf8");
    struct Pessoa p1, p2;

    strcpy(p1.nome, "Maria Verônica");
    p1.idade = 58;
    p1.peso = 82.200;
    strcpy(p1.endereco.rua, "Doutor João Franca");
    p1.endereco.numero = 35;
    strcpy(p1.endereco.cep, "57.854-190");
    strcpy(p1.endereco.estado, "São Paulo");
    strcpy(p1.endereco.cidade, "São Paulo");

    strcpy(p2.nome, "João Silva");
    p2.idade = 45;
    p2.peso = 80.2;
    strcpy(p2.endereco.rua, "Rua das Flores");
    p2.endereco.numero = 120;
    strcpy(p2.endereco.cep, "12.345-678");
    strcpy(p2.endereco.estado, "Rio de Janeiro");
    strcpy(p2.endereco.cidade, "Rio de Janeiro");

    printf("\nDados do Funcionário:\n");

    imprimirPessoa(p1);
    imprimirPessoa(p2);

    return 0;
}