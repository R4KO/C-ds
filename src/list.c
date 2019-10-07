//
// Created by thoma on 17/11/2018.
//
#include <stdio.h>
#include <stdlib.h>
#include "../include/list.h"

node_list* new_node(int ex){
    node_list* l = malloc(sizeof(node_list));
    l->key = ex;
    l->next = NULL;
    return l;
};

node_list* init_list(int n){
    if(!n) return NULL;
    int a;
    printf("Please enter the key of the node %d: ", n);
    scanf("%d", &a);
    node_list* l = new_node(a);
    l->next = init_list(n-1);
}

void print_list_rec(node_list* l) {
    if (!l) printf("\n---------------------FIN---------------------\n");
    else {
        printf("%d\n", l->key);
        print_list_rec(l->next);
    }
}

void print_1_list(node_list* l, unsigned n){
    if(!l) printf("Empty list\n");
    else if(((n-1) != 0)&&(l->next))
        print_1_list(l->next, n-1);
    else if(n-1 == 0) printf("%d\n", l->key);
    else printf("Out of range\n");
}

int return_1_list(node_list* l, unsigned n){
    if(!l) {
        printf("Empty list\n");
        return NULL;
    }
    else if(((n-1) != 0)&&(l->next)) {
        return return_1_list(l->next, n - 1);
    }
    else if(n-1 == 0) return l->key;
    else {
        printf("Out of list range\n");
        return NULL;
    }
}

void free_list(node_list** l){
    if(*l) {
        free_list(&(*l)->next);
        free(*l);
        *l = NULL;
    }
}

int length(node_list* l){
    if(!l) return 0;
    return 1 + length(l->next);
}

int max(int a, int b){
    return a >= b ? a : b;
}