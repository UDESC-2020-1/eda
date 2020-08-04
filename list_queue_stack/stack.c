#include "stack.h"

typedef struct stack{
    list *list;
} stack;

/**
 * Cria uma nova pilha na memória.
 */
stack *stack_create(void){
    stack* result = malloc(sizeof(stack));

    result->list = list_create();

    return result;
}

/**
 * Limpa a memória de uma pilha.
 */
void stack_delete(stack *stack){
    list_delete(stack->list);
    free(stack);
}

/**
 * Adiciona um item no topo da pilha.
 */
void stack_push(stack *stack, int value){
    list_push_front(stack->list, value);
}

/**
 * Remove um item do fim da pilha.
 * Retorna zero se a pilha estiver vazia.
 */
int stack_pop(stack *stack){
    return list_pop_front(stack->list);
}

/**
 * Retorna o item no topo da pilha, sem remover ele.
 */
int stack_peek(stack *stack){
    int top = stack_pop(stack);
    stack_push(stack, top);
    return top;
}

/**
 * Retorna o tamanho de uma pilha.
 */
int stack_size(stack *stack){
    return list_size(stack->list);
}

/**
 * Verifica se uma pilha está vazia.
 */
int stack_empty(stack *stack){
    if (list_size(stack->list)==0){
        return 1;
    }
    return 0;
}
