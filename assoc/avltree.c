#include <stdlib.h>
#include <stdio.h>
#include <assert.h>
#include "avltree.h"

typedef struct node {
  int key;
  // int value;
  struct node *left;
  struct node *right;
} node;

struct avltree {
  node *root;
};

static void node_show(node *n) {
  printf("( ");
  if(n) {
    if(n->left) {
      node_show(n->left);
      printf(" ");
    }
    // Lembrar de colocar o valor!
    printf("%d ", n->key);
    if(n->right) {
      node_show(n->right);
      printf(" ");
    }
  }
  printf(")");
}

void avltree_show(avltree *t) {
  node_show(t->root);
  printf("\n");
}

avltree *avltree_create(void) {
  avltree *result = malloc(sizeof(avltree));

  result->root = NULL;

  return result;
}

int node_height(node *n) {
  if(n) {
    int l = 1 + node_height(n->left);
    int r = 1 + node_height(n->right);

    if(l > r) {
      return l;
    } else {
      return r;
    }
  }

  return 0;
}

int avltree_height(avltree *t) {
  return node_height(t->root);
}

/*
  Arruma uma sub-árvore com fator -1, rotacionando pela esquerda.

          a                       b
         / \                    /   \
        x   b                  a     c
           / \        =>      / \   / \
          y   c              x   y z   w
             / \
            z   w
*/
static node *left_rotate(node *a) {
  printf("Rotação à esquerda!\n");
  node *b = a->right;
  node *y = b->left;

  b->left = a;
  a->right = y;

  return b;
}

/*
  Arruma uma sub-árvore com fator 1, rotacionando pela direita.

          a                       b
         / \                    /   \
        b   x                  c     a
       / \            =>      / \   / \
      c   y                  z   w y   x
     / \
    z   w
*/
static node *right_rotate(node *a) {
  printf("Rotação à direita!\n");
  node *b = a->left;
  node *y = b->right;

  b->right = a;
  a->left = y;

  return b;
}

static node *node_insert(node *n, int k) {
  if(n) {
    if(n->key == k) {
      // Depois vamos lembrar de atualizar o valor!
      return n;
    }

    if(k < n->key) {
      n->left = node_insert(n->left, k);
    } else {
      n->right = node_insert(n->right, k);
    }

    // Verificamos os fatores!
    int factor = node_height(n->left) - node_height(n->right);

    if(factor < -1) {
      // Pendendo pra direita!
      if(k > n->right->key) {
        // Caso A: right right
        n = left_rotate(n);
      } else {
        // Caso B: right left!
        n->right = right_rotate(n->right);
        n = left_rotate(n);
      }
    } else if(factor > 1) {
      // Pendendo pra esquerda!
      if(k > n->left->key) {
        // Caso C: left right!
        n->left = left_rotate(n->left);
        n = right_rotate(n);
      } else {
        // Caso D: left left
        n = right_rotate(n);
      }
    }

    // Fizemos direito???
    factor = node_height(n->left) - node_height(n->right);
    assert(factor < 2 && factor > -2);

    return n;
  } else {
    n = malloc(sizeof(node));
    n->key = k;
    n->left = NULL;
    n->right = NULL;
    return n;
  }
}

void avltree_insert(avltree *t, int k) {
  t->root = node_insert(t->root, k);
}

void avltree_delete(avltree *t) {
  // Liberar os nós!
  free(t);
}
