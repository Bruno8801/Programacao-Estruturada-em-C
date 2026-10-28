#include <stdio.h>
#include <locale.h>

int main(void) {
    setlocale(LC_ALL,"Portuguese_Brazil.utf8");
    FILE *arquivo;
    int caractere;

    arquivo = fopen("../data/arq_leitura.txt", "r");

    if (arquivo != NULL) {
        // Lê caracter a caracter até o fim do arquivo
        while ((caractere = fgetc(arquivo)) != EOF) {
            printf("%c", caractere);
        }
        // Fecha o arquivo
        fclose(arquivo);
    } else {
        //Exibe caso haja erro na abertura do arquivo
        printf("Erro ao abrir o arquivo.\n");
    }
    return 0;
}