#include <stdlib.h>
#include <stdio.h>
#include "list.h"
#include "stack.h"
#include "queue.h"

int main() {

  // testando queue

  printf("queue:\n\n");

  queue *queue = queue_create();

  printf("enqueue(1)\n");
  queue_enqueue(queue, 1);
  printf("enqueue(2)\n");
  queue_enqueue(queue, 2);
  printf("enqueue(3)\n");
  queue_enqueue(queue, 3);

  printf("tamanho: %i\n", queue_size(queue));

  printf("dequeue: %i\n", queue_dequeue(queue));
  printf("dequeue: %i\n", queue_dequeue(queue));
  printf("dequeue: %i\n", queue_dequeue(queue));


  // testando stack
  printf("stack:\n\n");

  stack *stack = stack_create();

  printf("push(1)\n");
  stack_push(stack, 1);
  printf("push(2)\n");
  stack_push(stack, 2);
  printf("push(3)\n");
  stack_push(stack, 3);

  printf("tamanho: %i\n", stack_size(stack));
  printf("top: %i\n", stack_peek(stack));
  printf("pop: %i\n", stack_pop(stack));

  printf("push(10)\n");
  stack_push(stack, 10);
  printf("pop: %i\n", stack_pop(stack));

  printf("pop: %i\n", stack_pop(stack));
  printf("pop: %i\n", stack_pop(stack));
  stack_delete(stack);

  // testando list:

  list* lista = list_create();

  list_push_front(lista, 1);
  list_push_front(lista, 2);
  list_push_front(lista, 3);

  printf("%i\n", list_pop_back(lista));

  list_push_front(lista, 3);
  printf("%i\n", list_pop_back(lista));

  printf("%i\n", list_pop_back(lista));
  printf("%i\n", list_pop_back(lista));


  list_delete(lista);

  return EXIT_SUCCESS;
}
