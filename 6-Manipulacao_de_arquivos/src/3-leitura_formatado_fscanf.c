#include <stdio.h>
#include <locale.h>

int main(void) {
    setlocale(LC_ALL,"Portuguese_Brazil.utf8");
    setlocale(LC_NUMERIC,"C");

    FILE *arquivo;
    char url[] = "../data/arq_notas.txt", nome[50];
    float nota1, nota2, nota3;

    arquivo = fopen(url, "r");

    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo.\n");
    } else {
        while (fscanf(arquivo, "%49[^;];%f;%f;%f\n", nome, &nota1, &nota2, &nota3) == 4) {
            float media = (nota1 + nota2 + nota3) / 3;
            const char *resultado = (media >= 6) ? "aprovado" : "reprovado";
            printf("%s teve média: %.2f %s\n", nome, media, resultado);
        }
        fclose(arquivo);
    }
    return 0;
}