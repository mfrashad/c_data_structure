#include <stdio.h>
#include <stdlib.h>
#include "hashtable.h"

void init(ht_t *ht){
    ht = malloc(sizeof(ht_t));

    ht->size = 0;
    ht->capacity = CAPACITY;
    ht->buckets = calloc(CAPACITY, sizeof(bucket_t));
}

int hash(ht_t *ht, char *key){
    int sum = 0;
    for(int i=0; key[i] != "\0"; i++){
       sum += (int)key[i]; 
    }

    return sum % ht->capacity;
}

void insert(ht_t *ht, char *key, char *value){
    bucket_t *bucket = malloc(sizeof(bucket_t));
    bucket->key = key;
    bucket->value = value;

    int index = hash(ht, key);
    while(ht->buckets[index] != NULL && ht->buckets[index]->key == -1){
        ++index;
        index %= ht->capacity;
    }
    ht->buckets[index] = bucket;
    ht->size++;
}

void search(ht_t *ht, char *key){
    int index = hash(ht, key);
    while(ht->buckets[index] != NULL){
        if(ht->buckets[index]->key == key){
            return ht->buckets[index]->value;
        }
        ++index;
        index %= ht->capacity; 
    }
    return NULL;
}

