#include <stdio.h>
#include <string.h> // biblioteca para manipulação de strings
#include <ctype.h> // biblioteca para manipulação de caracteres
#include <locale.h>

int main(void) {
    setlocale(LC_ALL, "Portuguese_Brazil.utf8");
    char str1[50], str2[50];

    printf("Digite a primeira string: ");
    fgets(str1, sizeof(str1), stdin);
    str1[strcspn(str1, "\n")] = 0; // Remove o caractere de nova linha

    printf("Digite a segunda string: ");
    fgets(str2, sizeof(str2), stdin);
    str2[strcspn(str2, "\n")] = 0;

    // Comparando as strings e as convertendo para maiúsculas
    for (int i = 0; str1[i] != '\0'; i++) {
        str1[i] = toupper(str1[i]); // toupper converte o caractere para maiúsculo
    }
    for (int i = 0; str2[i] != '\0'; i++) {
        str2[i] = toupper(str2[i]);
    }
    if (strcmp(str1, str2) == 0) {
        printf("As strings %s e %s são iguais.\n", str1, str2);
    } else {
        printf("As strings %s e %s são diferentes.\n", str1, str2);
    }

    return 0;
}