#include <stdlib.h>
#include <stdio.h>

#include "vector.h"

int main(){

    printf("\tvector test:\n\n");

    vector *v = vector_create();

    vector_push(v, 1);
    vector_push(v, 2);
    vector_push(v, 3);


    vector_push(v, 4);
    vector_push(v, 5);
    vector_push(v, 6);
    vector_push(v, 7);
    vector_push(v, 8);
    vector_push(v, 9);
    vector_push(v, 10);
    vector_push(v, 11);
    vector_push(v, 12);
    
    for (int i=0; i<12; i++) printf("vector[%i] = %i\n", i, vector_get(v, i));

    vector_delete(v);

}