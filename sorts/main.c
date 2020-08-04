#include <stdio.h>
#include <stdlib.h>
#include "sort.h"

int main(){

    int vet_bubble[] = {2,3,5,4,1,2,9,6};

    bubble_sort(vet_bubble, 8);
    printf("\nbuble: \n");
    for (int i=0; i<8; i++){
        printf("%i ", vet_bubble[i]);
    }

    int vet_selection[] = {3,1,5,6,8,1,9,6};

    selection_sort(vet_selection, 8);
    printf("\nselection: \n");
    for (int i=0; i<8; i++){
        printf("%i ", vet_selection[i]);
    }

    int vet_insertion[] = {35,1,2,3,8,1,9,5};
    
    insertion_sort(vet_insertion, 8);
    printf("\ninsertion: \n");
    for (int i=0; i<8; i++){
        printf("%i ", vet_insertion[i]);
    }

    return EXIT_SUCCESS;
}