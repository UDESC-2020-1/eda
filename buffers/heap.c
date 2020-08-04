#include "heap.h"
#include <stdio.h>

int leftof(int i) {
  return 2 * i + 1;
}

int rightof(int i) {
  return 2 * i + 2;
}

/**
 * "Amontoa" uma sub-árvore em um buffer, a tornando em um heap.
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
  // Para criar um heap, precisamos "amontoar" as sub-árvores
  for(int i = n / 2 - 1; i >= 0; i--) {
    heapify(v, n, i);
  }
}

void heapsort(int *v, int n){
  int i=n/2;
  int paizao;
  int filhao;
  int nodo;
  while(1==1){
    if(i >0){
      i--;
      nodo = v[i];
    }
    else{
      n--; // index do último elemento
      nodo = v[n]; // referencia o nodo
      if(n<=0) break;
      v[n] = v[0];
    }

    filhao = leftof(i);
    paizao = i;
    while (filhao < n){ // aaaaaquiiiiiii tinha que quebrar pra nao dar segfault /edit: nao era isso
      if((filhao + 1 < n) && (v[filhao+1] > v[filhao])) filhao++; // se o da direita for maior, escolher ele

      if(v[filhao] > nodo){ // ai trocar o pai com o filho
        v[paizao] = v[filhao];
        paizao = filhao;
        filhao = leftof(paizao);
      }
      else break;
    }
    v[paizao]=nodo; // define o pai como o nodo e no proximo while vamos "excluir a última posição"
  }
}
