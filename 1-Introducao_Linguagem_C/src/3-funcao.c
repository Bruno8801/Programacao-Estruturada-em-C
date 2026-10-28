#include <stdio.h>
#include <locale.h>

int par_impar (int x); // todas funções subsequentes a main que irão ser usadas na mesma, devem ter seu nome declarado como variavel global no inicio do código
int main (void) {
    setlocale(LC_ALL,"Portuguese_Brazil.utf8");

    printf("Criando uma Função par_impar\n");
    int valor, resp;
    printf("Digite um valor para ser verificado: \n");
    scanf("%i", &valor);

    resp = par_impar(valor);

    return 0;
}

int par_impar (int x) { // caso não queira retornar nada use na declaração da função void. A declaração "int" dessa função é o valor do return, nesse caso foi um número inteiro
    if (x % 2 == 0) {
        return 1;
    } else {
        return 0;
    }
}
