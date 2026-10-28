/*
 * calloc significa "contiguous allocation" (alocação contígua).
 * Ela reserva espaço para vários elementos e inicializa todos os bytes
 * reservados com zero.
 */

#include <stdio.h>
#include <stdlib.h>

int main(void) {
	int quantidade;

	printf("Digite a quantidade de elementos do vetor: ");
	if (scanf("%d", &quantidade) != 1 || quantidade <= 0) {
		printf("Quantidade invalida. Digite um numero inteiro maior que zero.\n");
		return 1;
	}

	/*
	 * Sintaxe:
	 *     calloc(quantidade_de_elementos, tamanho_de_cada_elemento)
	 *
	 * Neste caso, reservamos espaco para 'quantidade' inteiros.
	 * O retorno de calloc e void*, que pode ser atribuido a int* em C.
	 */
	int *vetor = calloc(quantidade, sizeof(int));

	/* Sempre verifique se a alocacao foi bem-sucedida. */
	if (vetor == NULL) {
		printf("Erro na alocacao de memoria.\n");
		return 1;
	}

	printf("\nMemoria alocada com sucesso.\n");
	printf("Valores iniciais do vetor criado com calloc:\n");

	/*
	 * Diferentemente de malloc, calloc inicializa a memoria com zero.
	 * Por isso, os elementos podem ser lidos imediatamente neste exemplo.
	 */
	for (int indice = 0; indice < quantidade; indice++) {
		printf("vetor[%d] = %d\n", indice, vetor[indice]);
	}

	/* Podemos usar o vetor normalmente depois da alocacao. */
	vetor[0] = 10;
	if (quantidade > 1) {
		vetor[1] = 20;
	}

	printf("\nValores depois de algumas atribuicoes:\n");
	for (int indice = 0; indice < quantidade; indice++) {
		printf("vetor[%d] = %d\n", indice, vetor[indice]);
	}

	/*
	 * calloc apenas reserva e inicializa a memoria.
	 * Quando ela nao for mais necessaria, devemos libera-la com free.
	 */
	free(vetor);
	vetor = NULL; // Evita que o ponteiro continue apontando para memoria liberada.

	printf("\nMemoria liberada com sucesso.\n");

	return 0;
}
