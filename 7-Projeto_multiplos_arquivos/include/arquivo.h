#ifndef ARQUIVO_H
#define ARQUIVO_H

#include "candidato.h"

#include <stddef.h>

int carregar_candidatos(const char *caminho, Candidato candidatos[],
                        size_t capacidade, size_t *quantidade,
                        char *erro, size_t tamanho_erro);
int salvar_candidatos(const char *caminho, const Candidato candidatos[],
                      size_t quantidade, char *erro, size_t tamanho_erro);

#endif
