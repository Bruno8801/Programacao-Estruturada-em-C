#include <stdio.h>
#include <locale.h>
#include <string.h>

int main(void) {
    setlocale(LC_ALL,"Portuguese_Brazil.utf8");

    // comparando dados das strings
    char str1[50], str2[50];

    printf("Digite a primeira string: ");
    fgets(str1, sizeof(str1), stdin);
    str1[strcspn(str1, "\n")] = 0; // Remove o caractere de nova linha

    printf("Digite a segunda string: ");
    fgets(str2, sizeof(str2), stdin);
    str2[strcspn(str2, "\n")] = 0; // Remove o caractere de nova linha

    int resultado = strcmp(str1, str2);
    if (resultado == 0) {
        printf("As strings '%s' e '%s' são iguais.\n", str1, str2);
    } else if (resultado < 0) {
        printf("A string 1-'%s' é menor que 2-'%s'.\n", str1, str2);
    } else {
        printf("A string 1-'%s' é maior que 2-'%s'.\n", str1, str2);
    }

    return 0;
}