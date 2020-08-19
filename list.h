#ifndef UTILS_H
#define UTILS_H
#include "utils.h"
#endif

#ifndef STDIO_H
#define STDIO_H
#include <stdio.h>
#endif

#ifndef STDLIB_H
#define STDLIB_H
#include <stdlib.h>
#endif

typedef struct _node {
    char dest;
    struct _node *next;
} node;

typedef struct _list {
    array *chars;
    node **nodes;
} list;

node *new_node(char dest) {
    node *n = malloc(sizeof(node));
    n->dest = dest;
    n->next = NULL;
    return n;
}

void add_edge(list *g, char src, char dest) {
    int srcIndex = get_char_index(src, g->chars->array);
    int destIndex = get_char_index(dest, g->chars->array);
    
    node *n = new_node(destIndex);
    n->next = g->nodes[srcIndex];
    g->nodes[srcIndex] = n;

    n = new_node(srcIndex);
    n->next = g->nodes[destIndex];
    g->nodes[destIndex] = n; 
}

list *new_list(char **connections) {
    list *g = malloc(sizeof(list));
    g->chars = get_unique_chars(connections);
    g->nodes = malloc(g->chars->length * sizeof(node*));

    int i;
    for(i = 0; i < g->chars->length; i++) g->nodes[i] = NULL;

    i = 0;
    while(connections[i][0]
        && connections[i][1]) {
        add_edge(g, connections[i][0], connections[i][1]);
        i++;
    }

    return g;
}

void print_list(list *g) {
    int i;
    node *n;
    for(i = 0; i < g->chars->length; i++) {
        printf("%c: ", g->chars->array[i]);
        n = g->nodes[i];
        while(n) {
            printf("-> %c ", g->chars->array[n->dest]);
            n = n->next;            
        }
        printf("\n");
    }
}
