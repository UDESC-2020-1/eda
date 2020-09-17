#include <stdlib.h>
#include <stdio.h>
#include <assert.h>
#include <string.h>
#include "avltree.h"

typedef struct node {
  char *key;
  int value;

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
    printf("%s:%d ", n->key, n->value);
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

static int node_factor(node *n) {
  return node_height(n->left) - node_height(n->right);
}

static node *node_insert(node *n, const char *k, int v) {
  if(n) {
    // Compara a chave atual com a desejada
    int val = strcmp(n->key, k);

    if(val == 0) {
      // Atualizamos o valor!
      n->value = v;
      return n;
    }

    if(val > 0) {
      n->left = node_insert(n->left, k, v);
    } else {
      n->right = node_insert(n->right, k, v);
    }

    // Verificamos os fatores!
    int factor = node_factor(n);

    if(factor < -1) {
      // Pendendo pra direita!
      if(strcmp(k, n->right->key) > 0) {
        // Caso A: right right!
        n = left_rotate(n);
      } else {
        // Caso B: right left!
        n->right = right_rotate(n->right);
        n = left_rotate(n);
      }
    } else if(factor > 1) {
      // Pendendo pra esquerda!
      if(strcmp(k, n->left->key) > 0) {
        // Caso C: left right!
        n->left = left_rotate(n->left);
        n = right_rotate(n);
      } else {
        // Caso D: left left!
        n = right_rotate(n);
      }
    }

    return n;
  } else {
    // Cria o novo nó
    n = malloc(sizeof(node));
    // Precisamos também copiar a chave
    n->key = malloc(strlen(k) + 1);
    strcpy(n->key, k);
    n->value = v;
    n->left = NULL;
    n->right = NULL;
    return n;
  }
}

void avltree_insert(avltree *t, const char *k, int v) {
  t->root = node_insert(t->root, k, v);
}

static int node_lookup(node *n, const char *k) {
  if(n != NULL) {
    int val = strcmp(n->key, k);

    if(val == 0) {
      return n->value;
    }

    if(val > 0) {
      return node_lookup(n->left, k);
    } else {
      return node_lookup(n->right, k);
    }
  }

  return 0;
}

int avltree_lookup(avltree *t, const char *k) {
  return node_lookup(t->root, k);
}

static void node_delete(node *n) {
  if(n) {
    node_delete(n->left);
    node_delete(n->right);
    free(n->key);
    free(n);
  }
}

static node *node_find_min(node *n) {
  // Procura o valor mais à esquerda aqui!
  while(n->left) {
    n = n->left;
  }

  return n;
}

static node *node_remove(node *n, const char *k, int *v) {
  if(n != NULL) {
    int val = strcmp(n->key, k);

    if(val == 0) {
      // Esse é o nó que queremos remover!
      if(v != NULL) {
        // Informa o valor de retorno!
        *v = n->value;
      }

      // Temos menos de dois filhos?
      if(n->left == NULL || n->right == NULL) {
        // Se tivermos algo a esquerda, aux será o que estiver na esquerda
        // Se não tivermos, aux será o que estiver na direita
        // Como entramos aqui se ao menos um dos dois for NULL, aux também pode
        node *aux = n->left != NULL
                      ? n->left
                      : n->right;
        if(aux == NULL) {
          // Não tinha nenhum filho! Liberamos n
          node_delete(n);
          n = NULL;
        } else {
          // Libera a chave atual!
          free(n->key);

          // Copia os dados de aux para n, e libera aux (o filho em questão)
          *n = *aux;
          free(aux);
        }
      } else {
        // Procura o menor item na direita!
        node *aux = node_find_min(n->right);

        // Atualiza o nosso nó
        free(n->key);
        n->key = malloc(strlen(aux->key) + 1);
        strcpy(n->key, aux->key);

        // Atualiza a direita, removendo o menor item de lá
        n->right = node_remove(n->right, aux->key, &n->value);
      }
    } else if(val > 0) {
      n->left = node_remove(n->left, k, v);
    } else if(val < 0) {
      n->right = node_remove(n->right, k, v);
    }

    // Se não foi ESSE nó que removemos, podemos precisar balancear!
    if(n != NULL) {
      // Podemos ter desbalanceado, então verificamos os fatores!
      int factor = node_height(n->left) - node_height(n->right);

      if(factor < -1) {
        // Pendendo pra direita!
        if(node_factor(n->right) <= 0) {
          // Caso A: right right!
          n = left_rotate(n);
        } else {
          // Caso B: right left!
          n->right = right_rotate(n->right);
          n = left_rotate(n);
        }
      } else if(factor > 1) {
        // Pendendo pra esquerda!
        if(node_factor(n->left) < 0) {
          // Caso C: left right!
          n->left = left_rotate(n->left);
          n = right_rotate(n);
        } else {
          // Caso D: left left!
          n = right_rotate(n);
        }
      }
    }

    // Retorna o nó atual
    return n;
  }

  // Se cair aqui, o item não existia na árvore!
  return NULL;
}

int avltree_remove(avltree *t, const char *k) {
  int res = 0;
  t->root = node_remove(t->root, k, &res);
  return res;
}

static int node_size(node *n) {
  if(n) {
    return 1 + node_size(n->left) + node_size(n->right);
  }
  return 0;
}

int avltree_size(avltree *t) {
  return node_size(t->root);
}

static bool node_balanced(node *n) {
  if(n) {
    int factor = node_factor(n);

    // Um nó está balanceado se tem um fator entre -1 e 1, e seus filhos estão
    // também balanceados
    return (factor == 0 || factor == 1 || factor == -1)
            && node_balanced(n->left)
            && node_balanced(n->right);
  }

  return true;
}

bool avltree_balanced(avltree *t) {
  return node_balanced(t->root);
}

void avltree_delete(avltree *t) {
  node_delete(t->root);
  free(t);
}
