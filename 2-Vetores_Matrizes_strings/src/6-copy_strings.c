#include <stdio.h>
#include <locale.h>
#include <string.h>

int main(void) {
    setlocale(LC_ALL, "Portuguese_Brazil.utf8");

    // --- LEMBRETE: O PERIGO DO STRCPY ---
    // strcpy não checa tamanho. Se 'origem' for maior que o 'destino', estoura a pilha (Buffer Overflow).
    char destino_curto[10];
    char origem_longa[] = "Olá, mundo! estou estudando linguagem C";

    // --- PRÁTICA SEGURA: STRNCPY ---
    // Sempre limitar a cópia ao tamanho do buffer de destino.
    char destino_seguro[50];
    
    // sizeof(destino_seguro) - 1 garante espaço para o caractere nulo '\0'
    strncpy(destino_seguro, origem_longa, sizeof(destino_seguro) - 1);
    
    // IMPORTANTE: strncpy pode não colocar o '\0' se o limite for atingido.
    // Garantindo manualmente o fechamento da string para evitar lixo de memória.
    destino_seguro[sizeof(destino_seguro) - 1] = '\0';

    printf("[DICA SEGURANÇA] Texto truncado com sucesso: %s\n\n", destino_seguro);

//----------------------------------------------------------------

    // --- MANIPULAÇÃO: CÓPIA PARCIAL ---
    // Útil para extrair partes específicas de uma string.
    char stack_tech[] = "Java e C - Linguagens Favoritas";
    char so_java[5];

    strncpy(so_java, stack_tech, 4); // Pega apenas "Java"
    so_java[4] = '\0'; // Finaliza a string na posição exata

    printf("[DICA MANIPULAÇÃO] Extração parcial: %s\n\n", so_java);

//----------------------------------------------------------------
    
    // --- CASO REAL: FGETS + STRNCPY ---
    // Simulando entrada de usuário para banco de dados.
    char buffer_entrada[100];
    char nome_cadastro[50];

    printf("Digite seu nome completo: ");
    fgets(buffer_entrada, sizeof(buffer_entrada), stdin);
    
    // Removendo o '\n' que o fgets traz do Enter
    buffer_entrada[strcspn(buffer_entrada, "\n")] = 0;

    // Copiando para o destino final respeitando o limite do "banco de dados"
    strncpy(nome_cadastro, buffer_entrada, sizeof(nome_cadastro) - 1);
    nome_cadastro[sizeof(nome_cadastro) - 1] = '\0';

    printf("[CADASTRO] Nome limpo e armazenado: %s\n", nome_cadastro);

    return 0;
}