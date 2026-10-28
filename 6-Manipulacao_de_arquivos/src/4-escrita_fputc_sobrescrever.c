#include <stdio.h>

int main(void) {
    FILE *arquivo;
    char msg[] = "Gravando uma nova mensagem no arquivo usando fputc()";

    arquivo = fopen("../data/arq_fputc.txt", "w");

    if (arquivo != NULL) {
        for (int i = 0; msg[i] != '\0'; i++) {
            fputc(msg[i], arquivo);
        }
        fclose(arquivo);
        printf("Mensagem escrita no arquivo com sucesso.\n");
    } else {
        printf("Erro ao abrir o arquivo.\n");
    }
    return 0;
}