# Variáveis de compilação
CC = gcc
CFLAGS = -I./SDL2/i686-w64-mingw32/include
LDFLAGS = -L./SDL2/i686-w64-mingw32/lib
LDLIBS = -lmingw32 -lSDL2main -lSDL2 -lSDL2_image

# Arquivos fonte
SRCS = main.c impl_jogo.c impl_pilha.c
OBJS = $(SRCS:.c=.o)

# Nome do executável
TARGET = programa.exe

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CC) $(LDFLAGS) -o $@ $^ $(LDLIBS)

%.o: %.c
	$(CC) $(CFLAGS) -c -o $@ $<

# Limpar arquivos .o e o executável ao compilar
.PHONY: all
all: clean

clean:
	del /Q $(OBJS)

.PHONY: clean