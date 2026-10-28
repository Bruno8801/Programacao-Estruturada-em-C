CC = gcc
CFLAGS = -std=c11 -Wall -Wextra -pedantic -Iinclude -finput-charset=UTF-8 -fexec-charset=UTF-8
TARGET = bin/cadastro_concurso.exe
SOURCES = src/3-multiplos_arquivos.c lib/candidato.c lib/arquivo.c

.PHONY: all clean run

ifeq ($(OS),Windows_NT)
REMOVE_TARGET = cmd /C "if exist bin\\cadastro_concurso.exe del /Q bin\\cadastro_concurso.exe"
else
REMOVE_TARGET = rm -f $(TARGET)
endif

all: $(TARGET)

$(TARGET): $(SOURCES) include/candidato.h include/arquivo.h
	$(CC) $(CFLAGS) $(SOURCES) -o $(TARGET)

run: $(TARGET)
	./$(TARGET)

clean:
	$(REMOVE_TARGET)
