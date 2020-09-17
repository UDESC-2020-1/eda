#pragma once
#include <stdbool.h>

typedef struct avltree avltree;

avltree *avltree_create(void);

void avltree_show(avltree *);

int avltree_height(avltree *);

void avltree_insert(avltree *, const char *, int);

int avltree_lookup(avltree *, const char *);

int avltree_remove(avltree *, const char *);

int avltree_size(avltree *);

bool avltree_balanced(avltree *);

void avltree_delete(avltree *);
