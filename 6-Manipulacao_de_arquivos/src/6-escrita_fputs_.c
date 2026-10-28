#include <stdio.h>

int main(void) {
    FILE *arquivo;
    char string1[] = "Essa é a primeira string.";
    char string2[] = "Essa é a segunda string";

    arquivo = fopen("../data/arq_fputs.txt", "w");

    if (arquivo != NULL) {
        fputs(string1, arquivo);
        fputs("\n", arquivo);
        fputs(string2, arquivo);

        fclose(arquivo);
        printf("Strings escritas no arquivo com sucesso.\n");
    } else {
        printf("Erro ao abrir o arquivo.\n");
    }
    return 0;
}
