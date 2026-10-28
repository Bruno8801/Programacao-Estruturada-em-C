#include <stdio.h>
#include <locale.h>
#include <string.h>

int main(void) {
    setlocale(LC_ALL,"Portuguese_Brazil.utf8");
    char frase[50] = "A linguagem C é poderosa!";
    char buscar[50];
    char caractere[2];
    char *resultado_nome;
    char *resultado_caractere;

    printf("Digite o nome para buscar na frase: ");
    if (fgets(buscar, sizeof(buscar), stdin) == NULL) {
        return 1;
    }
    buscar[strcspn(buscar, "\n")] = 0; // Remove o caractere de nova linha

    printf("Digite o caracter para buscar na frase: ");
    if (fgets(caractere, sizeof(caractere), stdin) == NULL) {
        return 1;
    }
    caractere[strcspn(caractere, "\n")] = 0;

    resultado_nome = strstr(frase, buscar);
    resultado_caractere = caractere[0] != '\0'
        ? strchr(frase, caractere[0])
        : NULL;

    if (resultado_nome != NULL && buscar[0] != '\0') {
        printf("O texto '%s' foi encontrado na posição %d.\n", buscar, (int)(resultado_nome - frase));
    } else {
        printf("O texto '%s' não foi encontrado na frase.\n", buscar);
    }

    if (resultado_caractere != NULL) {
        printf("O caractere '%s' foi encontrado na posição %d.\n", caractere, (int)(resultado_caractere - frase));
    } else {
        printf("O caractere '%s' não foi encontrado na frase.\n", caractere);
    }
    
    return 0;
}