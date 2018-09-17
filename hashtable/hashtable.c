#include <stdio.h>
#include <stdlib.h>
#include "hashtable.h"

#define CAPACITY 100

ht_t* new_hashtable(){
    ht_t *ht = malloc(sizeof(ht_t));

    ht->size = 0;
    ht->capacity = CAPACITY;
    ht->buckets = calloc(CAPACITY, sizeof(bucket_t));
    return ht;
}

void resize(ht_t **ht){
    float load = (float)(*ht)->size / (float)(*ht)->capacity;
    if(load >= 0.75){
        ht_t *new_ht = malloc(sizeof(ht_t));
        new_ht->size = 0;
        new_ht->capacity = (*ht)->capacity * 2;
        new_ht->buckets = calloc(new_ht->capacity, sizeof(bucket_t));
        for(int i=0; i < (*ht)->capacity; i++){
            if((*ht)->buckets[i] != NULL && (*ht)->buckets[i]->key){
                insert(&new_ht, (*ht)->buckets[i]->key, (*ht)->buckets[i]->value); 
            }
        }
        *ht = new_ht;
    }
}

int hash(ht_t *ht, char *key){
    int sum = 0;
    for(int i=0; key[i] != '\0'; i++){
       sum += (int)key[i]; 
    }

    return sum % ht->capacity;
}

void insert(ht_t **ht, char *key, char *value){
    
    resize(ht);
    int index = hash(*ht, key);
    while((*ht)->buckets[index] != NULL && (*ht)->buckets[index]->key[0] == '\0'){
        ++index;
        index %= (*ht)->capacity;
    }

    (*ht)->buckets[index] = malloc(sizeof(bucket_t));
    (*ht)->buckets[index]->key = key;
    (*ht)->buckets[index]->value = value;

    (*ht)->size++;
}

char* search(ht_t *ht, char *key){
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

void delete_bucket(ht_t *ht, char* key){
    int index = hash(ht, key);
    while(ht->buckets[index] != NULL){
        if(ht->buckets[index]->key == key){
            printf("deleting {\"%s\" : \"%s\"}\n", ht->buckets[index]->key, ht->buckets[index]->value);
            ht->buckets[index]->key = '\0';
            ht->buckets[index]->value = '\0';
            ht->size--;
            return;
        }
        ++index;
        index %= ht->capacity;
    } 
    printf("key \"%s\" not found\n", key);
}

void print(ht_t *ht){
    printf("\nHashtable Values: \n");
    for(int i=0; i < ht->capacity; i++) {
        if(ht->buckets[i] != NULL && ht->buckets[i]->key){
            printf("{\"%s\" : \"%s\"}\n", ht->buckets[i]->key, ht->buckets[i]->value);
        }
    }
    printf("\n");
}
