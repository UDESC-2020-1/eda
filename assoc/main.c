#include <stdlib.h>
#include <stdio.h>
#include "tree.h"

/*
  ( ( ( 25 ) 50 ( 75 ) ) 100 ( ( 150 ) 200 ( 250 ) ) )

        100
     /       \
    50       200
   /  \     /   \
  25  75   150 250
*/

static void show_value(int k) {
  printf(" %d", k);
}

int main() {
  tree *t = tree_create();

  printf("Árvore:\n");
  tree_show(t);

  /* tree_insert(t, 100);
  tree_insert(t, 200);
  tree_insert(t, 50);
  tree_insert(t, 25);
  tree_insert(t, 75);
  tree_insert(t, 150);
  tree_insert(t, 250); */

  for(int i = 0; i < 16; i++) {
    tree_insert(t, i % 1000);
  }

  printf("Árvore:\n");
  tree_show(t);

  printf("Altura: %d, tamanho = %d\n", tree_height(t), tree_size(t));

  // printf("Pré-ordem:\n");
  // tree_preorder(t, show_value);
  // printf("\n");

  // printf("Em-ordem:\n");
  // tree_inorder(t, show_value);
  // printf("\n");

  // printf("Pós-ordem:\n");
  // tree_postorder(t, show_value);
  // printf("\n");

  printf("Balanceando a árvore!\n");
  tree_balance(t);

  printf("Árvore:\n");
  tree_show(t);

  printf("Altura: %d, tamanho = %d\n", tree_height(t), tree_size(t));

  tree_delete(t);

  return EXIT_SUCCESS;
}
