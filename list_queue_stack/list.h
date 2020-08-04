/*******************************************************************************
* Arquivo contendo a declaração de uma lista linkada.                          *
*******************************************************************************/
#pragma once

#include <stdlib.h>

/**
 * Declara uma estrutura "list" abstrata.
 */
typedef struct list list;

/**
 * Cria uma nova lista na memória.
 */
list *list_create(void);

/**
 * Limpa a memória de uma lista.
 */
void list_delete(list *);

/**
 * Adiciona um item no começo da lista.
 */
void list_push_front(list *, int);

/**
 * Adiciona um item no fim da lista.
 */
void list_push_back(list *, int);

/**
 * Remove um item do começo da lista.
 * Retorna zero se a lista estiver vazia.
 */
int list_pop_front(list *);

/**
 * Remove um item do fim da lista.
 * Retorna zero se a lista estiver vazia.
 */
int list_pop_back(list *);

/**
 * Retorna o tamanho de uma lista.
 */
int list_size(list *);
