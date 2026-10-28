#ifndef CANDIDATO_H
#define CANDIDATO_H

#include <stddef.h>

#define MAX_CANDIDATOS 1000
#define NOTA_MINIMA_APROVACAO 70.0f

typedef struct {
    char nome[100];
    char data_nascimento[11];
    char cpf[12];
    float pontuacao;
} Candidato;

void candidatos_ordenar(Candidato candidatos[], size_t quantidade);
const Candidato *candidato_buscar_cpf(const Candidato candidatos[],
                                      size_t quantidade, const char cpf[12]);

#endif
