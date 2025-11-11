# Makefile para o Projeto de Análise Ambiental em C

# Compilador
CC = gcc

# Flags de compilação:
# -Wall -Wextra = Habilita todos os avisos (warnings)
# -std=c99       = Usa o padrão C99
# -g             = Inclui símbolos de debug (para usar o gdb)
# -lm            = Linka a biblioteca de matemática (obrigatória para sqrt, pow, etc.)
CFLAGS = -Wall -Wextra -std=c99 -g -lm

# Diretórios
SRCDIR = src
INCDIR = include
OBJDIR = obj

# Nome do executável
TARGET = analise_ambiental

# Encontra todos os arquivos .c no diretório src
SOURCES = $(wildcard $(SRCDIR)/*.c)

# Cria nomes de arquivos objeto (.o) correspondentes na pasta obj
OBJECTS = $(patsubst $(SRCDIR)/%.c, $(OBJDIR)/%.o, $(SOURCES))

# Flag para incluir o diretório de cabeçalhos
CPPFLAGS = -I$(INCDIR)

# --- Regras ---

# Regra principal: compila o executável final
all: $(TARGET)

# Regra para linkar o executável final a partir dos arquivos .o
$(TARGET): $(OBJECTS)
	$(CC) $(CFLAGS) -o $@ $^

# Regra para compilar arquivos .c em .o
# Cria o diretório de objetos se ele não existir
$(OBJDIR)/%.o: $(SRCDIR)/%.c | $(OBJDIR)
	$(CC) $(CFLAGS) $(CPPFLAGS) -c -o $@ $<

# Regra para criar o diretório de objetos
$(OBJDIR):
	mkdir -p $(OBJDIR)

# Regra para limpar os arquivos compilados
clean:
	rm -rf $(OBJDIR) $(TARGET) resultados.csv

# Regra "phony" para garantir que 'all' e 'clean' sempre rodem
.PHONY: all clean
