#ifndef SUN_H
#define SUN_H

typedef struct node{
    int node_num;
}node;

typedef struct center_node{
    node *children;
    int count;
    int capacity;
} center_node;


void init_center(center_node *c, int capacity);

void add_nodes(center_node *c, int node_num);

void remove_node(center_node *c, int node_num);

void print_nodes(center_node *c);

void free_center(center_node *c);

#endif

