#include <stdio.h>
#include <locale.h>
#include <string.h>

void trocar(char *a, char *b) {
    char temp = *a;
    *a = *b;
    *b = temp;
}

void permutar(char *string, int inicio, int fim) {
    if (inicio == fim) 
        printf("%s\n", string);
    else {
        for (int i = inicio; i <= fim; i++) {
            trocar((string + inicio), (string + i));
            permutar(string, inicio + 1, fim);
            trocar((string + inicio), (string + i)); // reverte a troca
        }
    }
}

unsigned int fatorial(unsigned int n) { // função para calcular o total de combinações utilizando fatoração
    if (n == 0)
        return 1;
    else
        return n * fatorial(n - 1);
}

int main(void) {
    setlocale(LC_ALL,"Portuguese_Brazil.utf8");
    char str[] = "ABC";
    int tamanho = strlen(str);
    unsigned int total = fatorial((unsigned int)tamanho);
    
    printf("Todas as permutações de %s são:\n", str);
    printf("Com o total de %u combinações:\n", total);
    permutar(str, 0, tamanho - 1);
    
    return 0;
}