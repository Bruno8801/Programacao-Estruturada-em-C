#include "candidato.h"

#include <string.h>

void candidatos_ordenar(Candidato candidatos[], size_t quantidade) {
    size_t i;

    for (i = 1; i < quantidade; i++) {
        Candidato atual = candidatos[i];
        size_t j = i;

        while (j > 0 && candidatos[j - 1].pontuacao < atual.pontuacao) {
            candidatos[j] = candidatos[j - 1];
            j--;
        }
        candidatos[j] = atual;
    }
}

const Candidato *candidato_buscar_cpf(const Candidato candidatos[],
                                      size_t quantidade, const char cpf[12]) {
    size_t i;

    for (i = 0; i < quantidade; i++) {
        if (strcmp(candidatos[i].cpf, cpf) == 0) {
            return &candidatos[i];
        }
    }

    return NULL;
}
