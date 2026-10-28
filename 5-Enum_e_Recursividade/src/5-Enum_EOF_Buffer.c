#include <stdio.h>
#include <locale.h>
        
enum dias_da_semana {
    DOMINGO,
    SEGUNDA,
    TERCA,
    QUARTA,
    QUINTA,
    SEXTA,
    SABADO
};
        
int main(void) {
    setlocale(LC_ALL,"Portuguese_Brazil.utf8");
    int dia;
    int verificacao; // variavel criada para evitar loop infinito ao digitar caracteres

    do {
        printf("Selecione um dia da semana de 0 a 6: ");
        verificacao = scanf("%d", &dia);

        if (verificacao != 1 || dia < DOMINGO || dia > SABADO) {
            printf("Opção inválida.\n");
            // limpeza do buffer do teclado ao digitar caracteres
            int c;
            while ((c = getchar()) != '\n' && c != EOF); // EOF limpa o buffer mesmo apos fechar o terminal acidentalmente evitando travar a maquina em loop invisível. Protocolo de segurança em programação em C.
            dia = -1;
        }
    } while (dia < DOMINGO || dia > SABADO);

    switch (dia) {
        case DOMINGO:
            printf("O dia selecionado foi DOMINGO\n");
            break;
        case SEGUNDA:
            printf("O dia selecionado foi SEGUNDA\n");
            break;
        case TERCA:
            printf("O dia selecionado foi TERÇA\n");
            break;
        case QUARTA:
            printf("O dia selecionado foi QUARTA\n");
            break;
        case QUINTA:
            printf("O dia selecionado foi QUINTA\n");
            break;
        case SEXTA:
            printf("O dia selecionado foi SEXTA\n");
            break;
        case SABADO:
            printf("O dia selecionado foi SÁBADO\n");
            break;
    }
    return 0;
}