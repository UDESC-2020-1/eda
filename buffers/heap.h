#pragma once

void make_heap(int *, int);

void heap_push(int *, int, int);
int heap_pop(int *, int);

void heap_sort(int *, int);

int leftof(int);
int rightof(int);
int parentof(int);
