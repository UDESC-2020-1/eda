#pragma once
#include <stdbool.h>

typedef struct avltree avltree;

avltree *avltree_create(void);

void avltree_show(avltree *);

int avltree_height(avltree *);

void avltree_insert(avltree *, int);

void avltree_delete(avltree *);
