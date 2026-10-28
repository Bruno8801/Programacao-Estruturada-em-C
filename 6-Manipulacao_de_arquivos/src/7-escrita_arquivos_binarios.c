#include <stdio.h>

typedef struct {
    int id;
    float value;
} Data;

int main(void) {
    Data data_out = {1, 123.45};
    Data data_in;

    // Abrir arquivo para escrita em modo binário "wb"
    FILE *file = fopen("../data/data.bin", "wb");
    if (file == NULL) {
        printf("Erro ao abrir o arquivo para escrita\n");
        return 1;
    }

    // Escrever dados no arquivo
    size_t written = fwrite(&data_out, sizeof(Data), 1, file);
    if (written != 1) {
        printf("Erro ao escrever no arquivo\n");
        fclose(file);
        return 1;
    } else {
        printf("Dados escritos com exito\n");
    }

    fclose(file);
    return 0;
}
