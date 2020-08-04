#include <stdlib.h>
#include <stdio.h>
#include "vector.h"

struct vector {
  int *buffer;
  int size;
  int capacity;
};

vector *vector_create(void) {
  vector *result = malloc(sizeof(struct vector));

  const int initial = 8;

  result->buffer = malloc(sizeof(int) * initial);
  result->size = 0;
  result->capacity = initial;

  return result;
}

int vector_get(vector *vector, int pos) {
  if(pos < 0) {
    return 0;
  }
  if(pos >= vector->size) {
    return 0;
  }
  return vector->buffer[pos];
}

void vector_push(vector *vector, int value) {
  vector->buffer[vector->size] = value;
  vector->size++;

  if(vector->size == vector->capacity) {
    // Poderia usar a função realloc(), mas vamos fazer manualmente...
    // vector->buffer = realloc(vector->buffer, new_capacity);

    int new_capacity = vector->capacity * 2;
    int *new_buffer = malloc(sizeof(int) * new_capacity);

    // Aqui também poderia usar memcpy(), mas...
    // memcpy(new_buffer, vector->buffer, sizeof(int) * vector->size);

    for(int i = 0; i < vector->size; i++) {
      new_buffer[i] = vector->buffer[i];
    }

    free(vector->buffer);
    vector->capacity = new_capacity;
    vector->buffer = new_buffer;
  }
}

void vector_pop(vector *vector) {
  if(vector->size > 0) {
    // Deixa o último item salvo como lixo! :)
    vector->size--;
  }
}

void vector_delete(vector *vector) {
  free(vector->buffer);
  free(vector);
}
