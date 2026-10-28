#include <stdio.h>
#include <locale.h>
#include <string.h>
#include <stdlib.h>

int main(void) {
    // Define o idioma do terminal para português do Brasil.
    // Obs: o nome da localidade muda conforme o sistema:
    //   - Linux e macOS: "pt_BR.UTF-8"
    //   - Windows: "Portuguese_Brazil.utf8"
    setlocale(LC_ALL,"Portuguese_Brazil.utf8");
    /* Define o padrão numérico para "C", garantindo que números de ponto flutuante usem ponto (.) como separador decimal. Isso evita problemas quando a localidade muda o separador para vírgula */
    setlocale(LC_NUMERIC, "C");
    
    char numeroStr[10] = "123";
    char num_float[10] = "1.253";
    
    int numero = atoi(numeroStr); // Converte string para inteiro
    printf("O valor inteiro é: %d\n", numero);
    
    double num_dobro = atof(num_float); // Converte string para ponto flutuante
    printf("O valor em ponto flutuante é: %.4f\n", num_dobro);

    return 0;
}