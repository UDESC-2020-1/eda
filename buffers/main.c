#include <stdlib.h>
#include <stdio.h>
#include "vector.h"
#include "circular.h"
#include "sort.h"

int main() {
  // Apenas um número primo qualquer
  const int s = 727;

  int v[s];

  for(int i = 0; i < s; i++) {
    v[i] = rand() % 1000;
  }

  bubble_sort(v, s);

  printf("v = {");
  for(int i = 0; i < s; i++) {
    printf(" %d", v[i]);
  }
  printf(" }\n");

  for(int i = 0; i < s; i++) {
    // Garante que deu bom
    if(binary_search(v, s, v[i])) {
      printf("%d existe em v!\n", v[i]);
    } else {
      printf("Deu ruim!");
      return EXIT_FAILURE;
    }
  }

  return EXIT_SUCCESS;
}
