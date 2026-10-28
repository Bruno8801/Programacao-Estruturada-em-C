# Cadastro e classificacao de concurso em C

Exemplo didatico de um programa C dividido em varios arquivos. Ele cadastra candidatos, salva os dados em `data/candidatos.csv`, permite consultar pelo CPF e atualiza a classificacao sempre que um candidato novo e gravado.

## Regra de classificacao

- A nota minima de aprovacao e `70.0`, definida por `NOTA_MINIMA_APROVACAO` em `include/candidato.h`.
- Os aprovados aparecem primeiro, do maior para o menor resultado.
- Os reprovados aparecem em seguida, tambem do maior para o menor resultado.
- A numeracao e geral e recalculada pela ordem da classificacao. Empates mantem a ordem em que os candidatos foram cadastrados.
- Os CPFs no arquivo inicial sao dados ficticios para demonstracao.

## Organizacao dos arquivos

- `include/`: declaracoes compartilhadas e o tipo `Candidato`.
- `lib/`: funcoes de ordenacao, consulta e leitura/escrita do arquivo.
- `src/`: funcao `main`, menu e interacao com o usuario.
- `data/`: arquivo CSV usado como pequeno banco de dados. Cada linha tem `nome;data;cpf;pontuacao`.
- `bin/`: executavel gerado pela compilacao.
- `Makefile`: automatiza a compilacao dos diferentes arquivos `.c` em um unico programa.

## Compilar e executar

Instale o GCC e o GNU Make (no MinGW, o comando do Make pode se chamar `mingw32-make`). No terminal aberto na pasta do projeto:

```sh
make
make run
```

No Windows, se o comando `make` nao existir:

```powershell
mingw32-make
.\bin\cadastro_concurso.exe
```

O programa espera ser iniciado com a pasta do projeto como diretorio atual para encontrar `data/candidatos.csv`. No VS Code, use a tarefa de build configurada neste projeto.

Para compilar manualmente sem Make:

```sh
gcc -std=c11 -Wall -Wextra -pedantic -Iinclude -finput-charset=UTF-8 -fexec-charset=UTF-8 src/3-multiplos_arquivos.c lib/candidato.c lib/arquivo.c -o bin/cadastro_concurso.exe
```

## O que cada comando do Makefile faz

- `make` ou `make all`: compila e cria `bin/cadastro_concurso.exe`.
- `make run`: compila se necessario e inicia o programa.
- `make clean`: remove o executavel para permitir uma compilacao limpa.

## Conceitos de C usados

- `#include "candidato.h"` compartilha tipos e prototipos entre arquivos.
- Cada `.c` e compilado separadamente e o linker junta os arquivos-objeto em um executavel.
- `struct Candidato` agrupa os dados de uma pessoa.
- Vetor de structs armazena os candidatos durante a execucao.
- `candidatos_ordenar` usa ordenacao por insercao, adequada para este exemplo pequeno.
- `fopen`, `fgets`, `fprintf` e `fclose` fazem a persistencia no arquivo CSV.
- Funcoes de validacao verificam data, CPF (11 digitos), nota (0 a 100) e CPF duplicado.

## Usar outro arquivo de dados

Os cadastros ficam em `data/candidatos.csv` e permanecem salvos entre execucoes. Para reiniciar o exemplo, substitua o conteudo desse arquivo pelas tres linhas originais de demonstracao. Cada linha deve seguir o formato:

```text
Nome Sobrenome;DD/MM/AAAA;12345678901;85.50
```

Este exemplo verifica o formato e a quantidade de digitos do CPF, mas nao implementa o calculo dos digitos verificadores oficiais.
