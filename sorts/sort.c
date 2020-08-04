#include "sort.h"

bool binary_search(int *v, int n, int x) {
  int first = 0;
  int last = n - 1;

  int middle = (first + last) / 2;
  while(first <= last) {
    if(v[middle] < x) {
      first = middle + 1;
    } else {
      if(v[middle] > x) {
        last = middle - 1;
      } else {
        return true;
      }
    }

    middle = (first + last) / 2;
  }

  return false;
}

void bubble_sort(int *v, int n) {
  while(n > 1) {
    for(int i = 0; i < n; i++) {
      if(v[i] > v[i + 1]) {
        int aux = v[i];
        v[i] = v[i + 1];
        v[i + 1] = aux;
      }
    }
    n--;
  }
}

void selection_sort(int *v, int n) {
  for (int i=0; i<n; i++){
    int min = i;
    for (int j=i+1; j<n; j++){
      if (v[j] < v[min]) min = j;
    }
    if (min!=i) swap(&v[i], &v[min]);
  }
}

void insertion_sort(int *v, int n) {
  for (int i=1; i<n; i++){
    int j = i;
    while (j>0 && v[j-1]>v[j]){
      swap(&v[j], &v[j-1]);
      j--;
    }
  }
}

void swap(int *a, int *b){
  int aux = *a;
  *a = *b;
  *b = aux;
}