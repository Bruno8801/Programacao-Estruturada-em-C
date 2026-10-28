#include <stdio.h>
#include <string.h>
#include <locale.h>

struct Pessoa {
    char nome[50];
    int idade;
};

void print_pessoa(struct Pessoa *pessoa) {
    printf("Nome: %s\n", pessoa->nome);
    printf("Idade: %d\n", pessoa->idade);
}

void alterar_idade(struct Pessoa *pessoa, int nova_idade) {
    pessoa->idade = nova_idade;
}

void alterar_nome(struct Pessoa *pessoa, const char *novo_nome) {
    // Recebe o texto sem permitir que a função altere a string original, isso evita de forma segura que o novo_texto não ultrapasse o limite, assim evitando overflow.
    strncpy(pessoa->nome, novo_nome, sizeof(pessoa->nome) - 1);

    // Garante o terminador, pois strncpy pode não adicioná-lo se o texto for longo.
    pessoa->nome[sizeof(pessoa->nome) - 1] = '\0';
}

int main(void) {
    setlocale(LC_ALL,"Portuguese_Brazil.utf8");
    struct Pessoa candidato[] = {
        {"Maria Antonieta", 28},
        {"João da Silva", 26},
        {"Billie Eilish", 25}
    
    };
    int size = sizeof(candidato) / sizeof(candidato[0]);
    for (int i = 0; i < size; i++) {
        print_pessoa(&candidato[i]);
        printf("\n");
    }

    // Modificar a idade e nome da pessoa dentro da função
    printf("\nAlterando a idade:\n");
    alterar_idade(&candidato[1], 30);
    print_pessoa(&candidato[1]);
    
    printf("\nAlterando o nome:\n");
    alterar_nome(&candidato[0], "Juliano Nobrega");
    print_pessoa(&candidato[0]);

    printf("\nLista de Candidatos atualizada:\n");
    for (int i = 0; i < size; i++) {
        print_pessoa(&candidato[i]);
        printf("\n");
    }

    return 0;
}
