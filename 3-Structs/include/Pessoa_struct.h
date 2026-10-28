#include  "Endereco_struct.h"
#ifndef Pessoa_struct
#define Pessoa_struct

struct Pessoa {
    char nome[50];
    int idade;
    float peso;
    struct Endereco endereco;
};

#endif