#include <stdio.h>

#if defined(__APPLE__)
#include <TargetConditionals.h>
#endif

/*
 * VERSAO identifica o alvo. Pode ser definida na compilacao; caso contrario, o pre-processador escolhe um nome conforme o sistema-alvo detectado.
 * Android deve ser testado antes de Linux porque tambem define __linux__.
 */
#ifndef VERSAO
#if defined(_WIN32)
#define VERSAO "Windows"
#elif defined(__ANDROID__)
#define VERSAO "Android"
#elif defined(__APPLE__) && TARGET_OS_IPHONE
#define VERSAO "iOS"
#elif defined(__APPLE__) && TARGET_OS_OSX
#define VERSAO "macOS"
#elif defined(__linux__)
#define VERSAO "Linux"
#else
#define VERSAO "Sistema nao identificado por este exemplo"
#endif
#endif

/*
 * A opcao pode ser alterada aqui ou na compilacao, por exemplo:
 * gcc -DENABLE_DIAGNOSTICOS=0 2-condicionais_compilacao.c -o exemplo
 */
#ifndef ENABLE_DIAGNOSTICOS
#define ENABLE_DIAGNOSTICOS 1
#endif

/*
 * DEBUG ativa mensagens para ajudar a verificar a compilacao e a execucao.
 * Exemplo: gcc -DDEBUG=1 2-condicionais_compilacao.c -o exemplo
 */
#ifndef DEBUG
#define DEBUG 0
#endif

int main(void) {
#if DEBUG
    printf("[DEBUG] Alvo de compilacao identificado: %s\n", VERSAO);
#else
    printf("Este executavel foi compilado para: %s\n", VERSAO);
#endif

#if ENABLE_DIAGNOSTICOS
    printf("Diagnosticos extras estao habilitados.\n");
#else
    printf("Diagnosticos extras estao desabilitados.\n");
#endif

    return 0;
}

/*
 * #if, #elif, #else e #endif sao diretivas do pre-processador. O compilador
 * define macros como _WIN32, __linux__ ou __APPLE__ conforme o alvo da compilacao. O pre-processador escolhe os trechos que serao compilados;
 * os outros trechos nem entram no programa final.
 * O mesmo codigo-fonte pode ser compartilhado, mas normalmente e preciso compilar uma versao para cada sistema (e arquitetura). Essas condicoes nao transformam um executavel Windows em um executavel Linux: cada binario depende do formato, das bibliotecas e das APIs do seu alvo. Ferramentas de compilacao cruzada ou CI podem gerar essas versoes a partir do mesmo codigo.
 * DEBUG controla mensagens que aparecem no terminal ao executar o programa.
 * VERSAO pode ser fornecida externamente para substituir a identificacao automatica, por exemplo numa compilacao de teste ou configuracao especifica.
 */
