#include <stdlib.h>
#include "list.h"

/**
 * Elo (link) em uma lista linkada. Uma lista irá lembrar quem é o primeiro e
 * quem é o último item contido. Cada elo referencia itens ao seu lado.
 *
 *                                      p
 *                         +------------------------+
 *               p         |                        |
 *    +--------------------+---+                    |
 *    |                    |   |                    |
 *   \ /                  \ /  |                    |
 *  +---+---+---+   n    +---+---+---+   n    +---+---+---+
 *  | x | . | . | -----> | y | . | . | -----> | z | . | . | ---> NULL
 *  +---+---+---+        +---+---+---+        +---+---+---+
 *   / \  | p                                  / \
 *    |   +---> NULL                            |
 *    |                                         +--- cauda
 *    +--- cabeça
 *
 * Cada item possui um valor (x, y, z) e pode apontar para um próximo item e
 * para um item anterior.
 */
typedef struct item {
  /// Valor do item atual
  int value;
  /// Próximo item
  struct item *next;
  /// Item anterior
  struct item *prev;
} item;

/**
 * Implementação de uma lista na forma de uma lista linkada. A lista sempre
 * lembra seu primeiro e último item.
 */
struct list {
  /// Começo da lista (cabeça)
  item *head;
  /// Fim da lista (cauda)
  item *tail;
};

list *list_create(void) {
  list *result = malloc(sizeof(list));

  // Limpa a memória
  result->head = NULL;
  result->tail = NULL;

  return result;
}

static void item_delete(item *item) {
  if(item) {
    item_delete(item->next);
    free(item);
  }
}

void list_delete(list *list) {
  item_delete(list->head);
  free(list);
}

void list_push_front(list *list, int value) {
  item *obj = malloc(sizeof(item));

  obj->next = list->head;
  obj->prev = NULL;
  obj->value = value;

  // Já temos algum item?
  if(list->head) {
    list->head->prev = obj;
    list->head = obj;
  } else {
    list->head = obj;
    list->tail = obj;
  }
}

void list_push_back(list *list, int value) {
  item *obj = malloc(sizeof(item));

  obj->next = NULL;
  obj->prev = list->tail;
  obj->value = value;

  // Já temos algum item?
  if(list->tail) {
    list->tail->next = obj;
    list->tail = obj;
  } else {
    list->head = obj;
    list->tail = obj;
  }
}

int list_pop_front(list *list) {
  if(list->head) {
    item *item = list->head;
    int result = item->value;

    // Tínhamos apenas um item?
    if(list->head == list->tail) {
      // Agora não temos nenhum
      list->head = NULL;
      list->tail = NULL;
    } else {
      // Remove a cabeça
      list->head = item->next;
      item->next->prev = NULL;
    }

    // Limpa a memória do item removido
    free(item);

    return result;
  }

  return 0;
}

int list_pop_back(list *list) {
  if(list->tail) {
    item *item = list->tail;
    int result = item->value;

    // Tínhamos apenas um item?
    if(list->head == list->tail) {
      // Agora não temos nenhum
      list->head = NULL;
      list->tail = NULL;
    } else {
      // Remove a cabeça
      list->tail = item->prev;
      item->prev->next = NULL;
    }

    // Limpa a memória do item removido
    free(item);

    return result;
  }

  return 0;
}

int list_size(list *list) {
  int count = 0;
  for(item *i = list->head; i != NULL; i = i->next) {
    count++;
  }

  return count;
}
