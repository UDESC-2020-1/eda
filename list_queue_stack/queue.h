/*******************************************************************************
* Arquivo contendo a declaração de uma fila (estrutura FIFO).                 *
*******************************************************************************/
#include <stdlib.h>
#include <stdbool.h>

/**
 * Declara uma estrutura "queue" abstrata.
 */
typedef struct queue queue;

/**
 * Cria uma nova fila na memória.
 */
queue *queue_create(void);

/**
 * Limpa a memória de uma fila.
 */
void queue_delete(queue *);

/**
 * Adiciona um item no fim da fila.
 */
void queue_enqueue(queue *, int);

/**
 * Retorna o item no começo da fila.
 * Retorna zero se a fila estiver vazia.
 */
int queue_dequeue(queue *);

/**
 * Retorna o item no começo da fila, sem remover ele.
 */
int queue_peek(queue *);

/**
 * Retorna o tamanho de uma fila.
 */
int queue_size(queue *);

/**
 * Verifica se uma fila está vazia.
 */
int queue_empty(queue *);
