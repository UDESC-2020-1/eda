#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <time.h>
#include <assert.h>
#include "vector.h"
#include "sort.h"
#include "heap.h"

static void verify_heap_property(int *v, int n, int i) {
  int l = leftof(i);
  int r = rightof(i);

  assert(parentof(l) == i);
  assert(parentof(r) == i);

  if(l < n) {
    assert(v[i] >= v[l]);
    verify_heap_property(v, n, l);
  }

  if(r < n) {
    assert(v[i] >= v[r]);
    verify_heap_property(v, n, r);
  }
}

static void print_heap_as_tree(int *v, int s) {
  int x = 0;
  int max = 4 * pow(2, (int)floor(log2(s)));
  int itens, used, spacing;

  printf("Vetor (tamanho = %d):\n", s);
  for(int i = 0; i < s; i++) {
    if((i & (i + 1)) == 0) {
      if(i) printf("\n");
      itens = (int)pow(2, x);
      used = 4 * itens;
      spacing = ((max - used) / itens) / 2;
      x++;
    }

    // Um código inelegante para imprimir o heap como uma árvore
    for(int j = 0; j < spacing; j++) printf(" ");
    printf("%4d", v[i]);
    for(int j = 0; j < spacing; j++) printf(" ");
  }
  printf("\n");
}

int main() {

  int s = 31;
  int v[s];

  // Inicia o vetor com valores aleatórios
  srand(time(NULL));
  for(int i = 0; i < s; i++) {
    // i = tamanho até agora
    print_heap_as_tree(v, i);
    heap_push(v, i, rand() % 1000);
    verify_heap_property(v, i, 0);
  }

  print_heap_as_tree(v, s);

  while(s) {
    int max = heap_pop(v, s--);
    printf("Valor máximo: %d\n", max);
    print_heap_as_tree(v, s);
    verify_heap_property(v, s, 0);
  }

  return EXIT_SUCCESS;
}
