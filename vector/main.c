#include <stdio.h>
#include "vector.h"


int main() {
    Vector vector;
    vector_init(&vector);

    for(int i=400; i>0; i-=50){
        vector_append(&vector, i);
    }

    vector_append(&vector, 4);
    vector_append(&vector, 1);
    vector_append(&vector, 9);
    vector_append(&vector, 3);
    vector_append(&vector, 3);

    vector_set(&vector, 30, 50);

    print(vector);
    printf("\n");
    insertion_sort(&vector);
    print(vector);

    vector_free(&vector);
}
