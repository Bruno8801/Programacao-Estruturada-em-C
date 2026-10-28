#include <stdio.h>
#include <stdlib.h>

int *get_array(int size) {
    // Alocação dinâmica de um array 'size' inteiro
    if (size <= 0) {
        return NULL;
    }

    int *array = malloc(sizeof(int) * size);

    if (array == NULL) {
        return NULL;
    }

    // Retorno do ponteiro para array alocado
    return array;
}

int main(void) {
    // Ponteiro 'array' recebe o ponteiro retornado pela função 'get_array'
    int *array = get_array(10);

    if (array == NULL) {
        fprintf(stderr, "Erro: nao foi possivel alocar o array.\n");
        return EXIT_FAILURE;
    }

    // Uso do array
    printf("Imprimindo array: \n");
    for (int i = 0; i < 10; i++) {
        array[i] = i;
        printf("%d ", array[i]);
    }
    printf("\n");

    free(array);
    return 0;
}