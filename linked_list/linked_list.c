#include <stdio.h>
#include <stdlib.h>
#include "linked_list.h"



void init(node_t **head){
    *head = malloc(sizeof(node_t));
    if (*head == NULL){
        exit(1);
    }

    (*head)->val = 0;
    (*head)->next = NULL;
}

void push(node_t *head, int val){
    node_t *current = head;
    while(current->next != NULL){
        current = current->next;
    }

    current->next = malloc(sizeof(node_t));
    current->next->val = val;
    current->next->next = NULL;
}

int pop(node_t *head){
    node_t *current = head;
    int retval = -1;

    if(current->next == NULL){
        retval = current->val;
        free(current);
        return retval;
    }
    while(current->next->next != NULL){
        current = current->next;
    }

    retval = current->next->val;
    free(current->next);
    current->next = NULL;
    return retval;
}

void print(node_t *head){
    node_t *current = head;

    while(current != NULL){
        printf("%d\n", current->val);
        current = current->next;
    }
}

void free_node(node_t *head){
    node_t *current = head;
    node_t *next = head->next;

    while(next != NULL){
        free(current);
        current = next;
        next = next->next;
    }
    free(current);
}
