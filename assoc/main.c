#include <stdlib.h>
#include <stdio.h>
#include "avltree.h"

/*
*/

int main() {

  avltree *t = avltree_create();

  avltree_show(t);

  for(int i = 0; i < 8; i++) {
    avltree_insert(t, rand() % 100);
    avltree_show(t);
  }

  avltree_delete(t);

  return EXIT_SUCCESS;
}
