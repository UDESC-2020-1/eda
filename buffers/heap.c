#include "heap.h"

int leftof(int i) {
  return 2 * i + 1;
}

int rightof(int i) {
  return 2 * i + 2;
}

int parentof(int i) {
  return (i - 1) / 2;
}

/**
 * "Amontoa" uma sub-árvore em um buffer, a tornando em um heap.
 *
 * Pré-condição: sub-árvores na esquerda e direita de i estão em prop. de heap.
 * Pós-condição: sub-árvore em i está em posição de heap.
 *
 * \param v Meu vetor.
 * \param n Tamanho do vetor (quantidade de elementos)
 * \param i Raiz da minha sub-árvore
 */
void heapify(int *v, int n, int i) {
  // Assumimos que o item na raiz é o maior...
  int largest = i;
  int l = leftof(i);
  int r = rightof(i);

  // O item na esquerda, se existir, é maior que a raiz?
  if(l < n && v[l] > v[largest]) {
    largest = l;
  }

  // O item na direita, se existir, é maior que a raiz?
  if(r < n && v[r] > v[largest]) {
    largest = r;
  }

  // Se a raiz não for o maior dos três nós...
  if(largest != i) {
    // Trocamos o valor...
    int aux = v[i];
    v[i] = v[largest];
    v[largest] = aux;

    // E repetimos o processo com o nó trocado como raiz
    heapify(v, n, largest);
  }
}

void make_heap(int *v, int n) {
  // Para criar um heap, precisamos "amontuar" as sub-árvores
  for(int i = n / 2 - 1; i >= 0; i--) {
    heapify(v, n, i);
  }
}

void heap_push(int *v, int n, int x) {
  v[n] = x;

  int p = parentof(n);
  while(n && v[p] < v[n]) {
    int aux = v[p];
    v[p] = v[n];
    v[n] = aux;

    n = p;
    p = parentof(n);
  }
}

int heap_pop(int *v, int n) {
  if(n--) {
    int max = v[0];
    v[0] = v[n];
    heapify(v, n, 0);

    return max;
  }

  return 0;
}

void heap_sort(int *v, int n) {
  //
}
