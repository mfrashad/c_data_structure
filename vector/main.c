#include <stdio.h>
#include "vector.h"

int main() {
    Vector vector;
    vector_init(&vector);

    for(int i=400; i>0; i-=50){
        vector_append(&vector, i);
    }

    vector_set(&vector, 30, 50);

    for(int i=0; i<vector.size; i++){
        printf("vector[%d] : %d \n", i, vector.data[i]);
    }


    vector_free(&vector);
}
