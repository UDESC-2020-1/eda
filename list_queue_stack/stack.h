/*******************************************************************************
* Arquivo contendo a declaração de uma pilha (estrutura LIFO).                 *
*******************************************************************************/
#include <stdlib.h>
#include <stdbool.h>
#include "list.h"

/**
 * Declara uma estrutura "stack" abstrata.
 */
typedef struct stack stack;

/**
 * Cria uma nova pilha na memória.
 */
stack *stack_create(void);

/**
 * Limpa a memória de uma pilha.
 */
void stack_delete(stack *);

/**
 * Adiciona um item no topo da pilha.
 */
void stack_push(stack *, int);

/**
 * Remove um item do fim da pilha.
 * Retorna zero se a pilha estiver vazia.
 */
int stack_pop(stack *);

/**
 * Retorna o item no topo da pilha, sem remover ele.
 */
int stack_peek(stack *);

/**
 * Retorna o tamanho de uma pilha.
 */
int stack_size(stack *);

/**
 * Verifica se uma pilha está vazia.
 */
int stack_empty(stack *);
