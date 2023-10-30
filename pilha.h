#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_STACK_SIZE 3

typedef struct stack* Pilha;

typedef int Tipo_Informacao;

void init(Pilha* pilha);

bool is_full(Pilha pilha);

bool is_empty(Pilha pilha);

bool push(Pilha pilha, Tipo_Informacao elemento);

bool pop(Pilha pilha, Tipo_Informacao* elemento);

// Imprime todas as torres
void to_print_todas(Pilha torres[]);

// Serve de complemento para a função acima
void complemento_to_print(int valor);

// retorna o elemento que está no topo da pilha
Tipo_Informacao get_info(Pilha pilha);