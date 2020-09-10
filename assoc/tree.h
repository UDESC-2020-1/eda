#include <stdbool.h>
#pragma once

typedef struct tree tree;

tree *tree_create(void);
void tree_delete(tree *);

void tree_show(tree *);

void tree_insert(tree *, int, int);

void tree_preorder(tree *, void (*)(int, int));
void tree_inorder(tree *, void (*)(int, int));
void tree_postorder(tree *, void (*)(int, int));

bool tree_has(tree *, int);
int tree_get(tree *, int);

int tree_size(tree *t);
int tree_height(tree *);

void tree_balance(tree *);
