#include "list.h"
#include "queue.h"

/**
 * Declara uma estrutura "queue" abstrata.
 */
typedef struct queue {
    list *list;
} queue;

/**
 * Cria uma nova fila na memória.
 */
queue *queue_create(void){
    queue *result = malloc(sizeof(queue));

    result->list = list_create();

    return result;
}

/**
 * Limpa a memória de uma fila.
 */
void queue_delete(queue *queue){
    list_delete(queue->list);
    free(queue);
}

/**
 * Adiciona um item no fim da fila.
 */
void queue_enqueue(queue *queue, int value){
    list_push_front(queue->list, value);
}

/**
 * Retorna o item no começo da fila.
 * Retorna zero se a fila estiver vazia.
 */
int queue_dequeue(queue *queue){
    if (queue_size(queue)==0){
        return 0;
    }
    return list_pop_back(queue->list);
}

/**
 * Retorna o item no começo da fila, sem remover ele.
 */
int queue_peek(queue *queue){
    int front = queue_dequeue(queue);
    list_push_back(queue->list, front);
    return front;
}

/**
 * Retorna o tamanho de uma fila.
 */
int queue_size(queue *queue){
    list_size(queue->list);
}

/**
 * Verifica se uma fila está vazia.
 */
int queue_empty(queue *queue){
    if (queue_size(queue)==0){
        return 1;
    }
    return 0;
}
