#include <stdio.h>

// Macro simples: o pré-processador substitui PI pelo texto 3.14159.
#define PI 3.14159

// Macros com parâmetros: use parênteses para evitar problemas de precedência.
#define SOMA(a, b) ((a) + (b))
#define QUADRADO(x) ((x) * (x))

int main(void) {
    double raio = 2.0;
    double area = PI * raio * raio;

    printf("Exemplo de macro simples:\n");
    printf("PI = %.5f\n", PI);
    printf("Area do circulo com raio %.1f = %.2f\n\n", raio, area);

    printf("Exemplos de macros com parametros:\n");
    printf("SOMA(3, 4) = %d\n", SOMA(3, 4));
    printf("QUADRADO(5) = %d\n", QUADRADO(5));
    printf("QUADRADO(3 + 2) = %d\n", QUADRADO(3 + 2));

    return 0;
}

/*
 * Importante:
 * - #define e #include sao diretivas do pre-processador: o # fica no inicio
 *   da diretiva. Antes da compilacao, o pre-processador faz substituicoes textuais, como PI por 3.14159.
 * - Uma macro nao e uma funcao. Ela nao tem verificacao de tipos como uma funcao e seus parametros podem ser avaliados mais de uma vez.
 *   Por exemplo, evite QUADRADO(i++), pois i++ seria avaliado duas vezes.
 * - Macros nao tornam necessariamente o programa menor ou mais rapido. O resultado depende do codigo gerado pelo compilador; use funcoes quando precisar de comportamento mais seguro e facil de depurar.
 */