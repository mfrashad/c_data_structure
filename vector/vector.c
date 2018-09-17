#include <stdio.h>
#include <stdlib.h>
#include "vector.h"

void vector_init(Vector *vector){
    vector->size = 0;
    vector->capacity = VECTOR_INITIAL_CAPACITY;
    vector->data = malloc(sizeof(int) * vector->capacity);
}

void vector_append(Vector *vector, int value){
    vector_double_capacity_if_full(vector);

    vector->data[vector->size++] = value;
}

int vector_get(Vector *vector, int index){
    if(index >= vector->size && index < 0){
        printf("Error: Index %d is out of bound", index);
        exit(1);
    }
    
    return vector->data[index];
}

void vector_set(Vector *vector, int index, int value){
    while(index >= vector->size){
        vector_append(vector, 0);
    }
    vector->data[index] = value;
}

void vector_double_capacity_if_full(Vector *vector){
    if(vector->size >= vector->capacity){
        vector->capacity *= 2;
        vector->data = realloc(vector->data, sizeof(int) * vector->capacity);
    }
}

void vector_free(Vector *vector){
    free(vector->data);
}

void buble_sort(Vector *vector){
    int swap_count = 0;
    do {
        swap_count = 0;
        for(int j=1; j < vector->size; j++){
            if(vector->data[j-1] > vector->data[j]){
                swap(&vector->data[j-1], &vector->data[j]);
                swap_count++;
            } 
        }
    } while(swap_count > 0);
}

void print(Vector vector){
    printf("[ ");
    for(int i=0; i < vector.size; i++){
        printf("%d, ", vector.data[i]);
    }
    printf("]\n");
}

void swap(int *a, int *b){
    int temp = *a;
    *a = *b;
    *b = temp;
}
