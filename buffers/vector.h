#pragma once

typedef struct vector vector;

vector *vector_create(void);
void vector_delete(vector *);

int vector_get(vector *, int);

void vector_push(vector *, int);
void vector_pop(vector *);
