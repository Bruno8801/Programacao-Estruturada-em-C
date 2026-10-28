#include <stdio.h>

typedef struct {
    int id;
    float value;
} Data;

int main(void) {
    Data data_in;
    FILE *file = fopen("../data/data.bin", "rb");
    if (file == NULL) {
        printf("Erro ao abrir o arquivo para leitura\n");
        return 1;
    }

    size_t read = fread(&data_in, sizeof(Data), 1, file);
    if (read != 1) {
        printf("Erro ao ler os dados do arquivo\n");
        fclose(file);
        return 1;
    }

    printf("ID: %d, Value: %.2f\n", data_in.id, data_in.value);

    fclose(file);
    return 0;
}