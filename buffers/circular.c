#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "circular.h"

struct circular {
  int *buffer;
  int capacity;
  int start;
  int final;
};

circular *circular_create(void) {
  const int initial = 4;

  circular *result = malloc(sizeof(struct circular));
  result->capacity = initial;
  result->start = 0;
  result->final = 0;
  result->buffer = malloc(sizeof(int) * initial);

  return result;
}

int circular_size(circular *c) {
  int result = c->final - c->start;

  // Se o final estiver antes do começo!
  if(result < 0) {
    result += c->capacity;
  }

  return result;
}

int circular_get(circular *c, int pos) {
  if(pos < 0) {
    return 0;
  }
  if(pos >= circular_size(c)) {
    return 0;
  }

  // Calcula a posição correta
  return c->buffer[(pos + c->start) % c->capacity];
}

static void circular_grow(circular *c) {
  // Os primeiros itens da lista começam em start e vão até capacity...
  int old_capacity = c->capacity;
  int first_half = old_capacity - c->start;

  // Primeiro, aumentamos a capacidade e alocamos um novo vetor
  c->capacity *= 2;
  int *new_buffer = malloc(sizeof(int) * c->capacity);

  // Agora, copiamos os dados, porém na ordem correta
  memcpy(new_buffer, c->buffer + c->start, sizeof(int) * first_half);
  memcpy(new_buffer + first_half, c->buffer, sizeof(int) * c->start);

  // Como agora os dados estão em ordem, devemos lembrar isso
  c->start = 0;
  c->final = old_capacity;

  // Finalmente, limpamos o buffer antigo e usamos o novo
  free(c->buffer);
  c->buffer = new_buffer;
}

void circular_push_back(circular *c, int v) {
  c->buffer[c->final] = v;
  c->final++;

  if(c->final == c->capacity) {
    c->final = 0;
  }

  // Estouramos o nosso limite!
  if(c->start == c->final) {
    circular_grow(c);
  }
}

void circular_push_front(circular *c, int v) {
  c->start--;
  if(c->start < 0) {
    c->start = c->capacity - 1;
  }

  c->buffer[c->start] = v;

  // Estouramos o nosso limite!
  if(c->start == c->final) {
    circular_grow(c);
  }
}

void circular_pop_back(circular *c) {
  // Se não estamos vazios...
  if(c->start != c->final) {
    // Apenas precisamos mover o cursor
    c->final--;
    if(c->final < 0) {
      c->final = c->capacity - 1;
    }
  }
}

void circular_pop_front(circular *c) {
  // Se não estamos vazios...
  if(c->start != c->final) {
    // Apenas precisamos mover o cursor
    c->start++;
    if(c->start == c->capacity) {
      c->start = 0;
    }
  }
}

void circular_delete(circular *c) {
  free(c->buffer);
  free(c);
}
