#include <stdio.h>
#include <locale.h>

int main(void) {
    setlocale(LC_ALL,"Portuguese_Brazil.utf8");
    FILE *arquivo;
    char linha[80];

    arquivo = fopen("../data/arq_leitura.txt", "r");
    int nlinha = 1;

    if (arquivo != NULL) {
        //Lê linha a linha até o fim do arquivo
        while (fgets(linha, sizeof(linha), arquivo) != NULL) {
            printf("Linha %d: %s", nlinha, linha);
            nlinha += 1;
        }
        fclose(arquivo);
    } else {
        printf("Erro ao abrir o arquivo.\n");
    }

    return 0;
}