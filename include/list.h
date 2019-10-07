//
// Created by thoma on 17/11/2018.
//

#ifndef LIST_H
#define LIST_H

typedef struct list{
    int key; // key of the node
    struct list *next;
}node_list;

node_list* new_node(int ex);

void print_list_rec(node_list* l);

void print_1_list(node_list* l, unsigned n);

int length(node_list* l);

int return_1_list(node_list* l, unsigned n);

void free_list(node_list** l);

#endif //LIST_H
