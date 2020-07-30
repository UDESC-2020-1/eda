#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <time.h>
#include "vector.h"
#include "sort.h"
#include "heap.h"

int main() {

  const int s = 31;
  int v[s];

  // Inicia o vetor com valores aleatórios
  srand(time(NULL));
  for(int i = 0; i < s; i++) {
    v[i] = rand() % 1000;
  }

  // Reordena o vetor para que ele tenha a propriedade de heap!
  make_heap(v, s);

  // Vamos imprimir e verificar o que fizemos...
  int x = 0;
  int max = 4 * pow(2, (int)floor(log2(s)));
  int itens, used, spacing;

  printf("Vetor:\n");
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

    // Verifica se fizemos tudo direito!
    int l = leftof(i);
    int r = rightof(i);

    if((l < s && v[l] > v[i]) || (r < s && v[r] > v[i])) {
      printf("Tem um bug aqui!\n");
      return EXIT_FAILURE;
    }
  }
  printf("\n");

  return EXIT_SUCCESS;
}
