#include <stdio.h>
#include <string.h>

void swap(char *a, char *b, int *x, int *y) {
    int temp = *x;
    char troca[20];

    *x = *y;
    *y = temp;

    strcpy(troca, a);
    strcpy(a, b);
    strcpy(b, troca);
}

int main(void) {
    char a[20] = "Maria";
    char b[20] = "Antonieta";
    int x = 10;
    int y = 20;

    swap(a, b, &x, &y);

    printf("a: %s, b: %s\nx: %d, y: %d", a, b, x, y);

    return 0;
}