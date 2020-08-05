#include <stdio.h>
#include <stdlib.h>

#include "circular.h"

int main(){

    circular *cb = circular_create();

    circular_push_back(cb, 3);
    circular_push_back(cb, 4);
    circular_push_back(cb, 5);

    circular_push_front(cb, 2);
    circular_push_front(cb, 1);

    circular_push_back(cb, 6);
    circular_push_back(cb, 7);
    circular_push_back(cb, 8);
    circular_push_back(cb, 9);


    printf("\nfor: \n");
    for (int i=0; i<circular_size(cb); i++){
        printf("%i\n", circular_get(cb, i));
    }


    circular_delete(cb);

}