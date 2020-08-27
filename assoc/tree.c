#include <stdlib.h>
#include <stdio.h>
#include "tree.h"

typedef struct node {
  int key;
  struct node *left;
  struct node *right;
} node;

struct tree {
  node *root;
};

tree *tree_create(void) {
  tree *result = malloc(sizeof(tree));
  result->root = NULL;

  return result;
}

void tree_delete(tree *t) {
  free(t);
}

static void node_show(node *n) {
  printf("( ");
  if(n) {
    if(n->left) {
      node_show(n->left);
      printf(" ");
    }
    printf("%d ", n->key);
    if(n->right) {
      node_show(n->right);
      printf(" ");
    }
  }
  printf(")");
}

void tree_show(tree *t) {
  node_show(t->root);
  printf("\n");
}

// Se o valor "k" já existir, retornamos o n que recebemos de argumento
// Caso contrário, retornamos um novo nó alocado na memória
static node *node_insert(node *n, int k) {
  if(n != NULL) {
    // Essa chave já existe?
    if(n->key == k) {
      // Não inserimos de novo, apenas retornamos!
      return n;
    }

    // Continuamos procurando!
    if(k < n->key) {
      n->left = node_insert(n->left, k);
      return n;
    } else {
      n->right = node_insert(n->right, k);
      return n;
    }
  } else {
    // Aloca um novo valor, a chave ainda não existia!
    n = malloc(sizeof(node));
    n->key = k;
    n->left = NULL;
    n->right = NULL;
    return n;
  }
}

void tree_insert(tree *t, int k) {
  // Inserir a chave "k" na árvore, caso ela já não exista!
  t->root = node_insert(t->root, k);
}

static void node_preorder(node *n, void (*f)(int)) {
  if(n) {
    f(n->key);
    node_preorder(n->left, f);
    node_preorder(n->right, f);
  }
}

void tree_preorder(tree *t, void (*f)(int)) {
  node_preorder(t->root, f);
}

static void node_inorder(node *n, void (*f)(int)) {
  if(n) {
    node_inorder(n->left, f);
    f(n->key);
    node_inorder(n->right, f);
  }
}

void tree_inorder(tree *t, void (*f)(int)) {
  node_inorder(t->root, f);
}

static void node_postorder(node *n, void (*f)(int)) {
  if(n) {
    node_postorder(n->left, f);
    node_postorder(n->right, f);
    f(n->key);
  }
}

void tree_postorder(tree *t, void (*f)(int)) {
  node_postorder(t->root, f);
}

bool tree_has(tree *t, int k) {
  node *n = t->root;
  while(n) {
    if(n->key == k) {
      return true;
    }
    if(n->key > k) {
      n = n->left;
    } else {
      n = n->right;
    }
  }

  return false;
}

static int node_size(node *n) {
  if(n) {
    return 1 + node_size(n->left) + node_size(n->right);
  }
  return 0;
}

int tree_size(tree *t) {
  return node_size(t->root);
}

static int node_height(node *n) {
  if(n) {
    int left_height = node_height(n->left);
    int right_height = node_height(n->right);
    if(left_height > right_height) {
      return left_height + 1;
    } else {
      return right_height + 1;
    }
  }

  return 0;
}

int tree_height(tree *t) {
  return node_height(t->root);
}

// ---------------------------------------------------------------------------

// Retorna quantos elementos foram inseridos!
static int node_place_inorder(node *n, node *v[]) {
  if(n) {
    // Já que inserimos i nós com a esquerda...
    int i = node_place_inorder(n->left, v);
    // O próximo lugar vazio é i! Aproveitamos e aumentamos i...
    v[i++] = n;
    // Agora precisamos inserir à direita...
    // Note que adicionamos um offset ao ponteiro!
    return i + node_place_inorder(n->right, v + i);
  }

  return 0;
}

static int tree_place_inorder(tree *t, node *v[]) {
  return node_place_inorder(t->root, v);
}

// Balanceia um vetor de nós ordenado!
static node *node_balance(node *v[], int start, int end) {
  if(start > end) {
    return NULL;
  }

  int middle = (start + end) / 2;

  node *root = v[middle];
  root->left = node_balance(v, start, middle - 1);
  root->right = node_balance(v, middle + 1, end);
  return root;
}

// Balanceia uma árvore em O(n)
void tree_balance(tree *t) {
  // Tamanho da árvore
  int size = tree_size(t);

  // Cria um vetor ordenado de nós!
  node **vector = malloc(sizeof(node *) * size);
  tree_place_inorder(t, vector);

  // Balanceia os nós ordenados!
  t->root = node_balance(vector, 0, size - 1);

  // Libera memória do vetor temporário
  free(vector);
}
