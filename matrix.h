#ifndef UTILS_H
#define UTILS_H
#include "utils.h"
#endif

#ifndef STDLIB_H
#define STDLIB_H
#include <stdlib.h>
#endif

typedef struct _matrix {
    array *chars;
    char **bits;
} matrix;

matrix *new_matrix(char **connections) {
    matrix *m = malloc(sizeof(matrix));
    m->chars = get_unique_chars(connections);
    m->bits = malloc(m->chars->length * sizeof(char*));

    int i, j;
    for(i = 0; i < m->chars->length; i++)
        for(j = 0; j < m->chars->length; j++)
            m->bits[i] = calloc(1, sizeof(char));

    i = 0;
    while(connections[i][0]
        && connections[i][1]) {
        m->bits[get_char_index(connections[i][0], m->chars->array)]
        [get_char_index(connections[i][1], m->chars->array)] = 1;

        m->bits[get_char_index(connections[i][1], m->chars->array)]
        [get_char_index(connections[i][0], m->chars->array)] = 1;
        i++;
    }
    return m;
}

void print_matrix(matrix *m) {
    printf("X ");
    int i, j;
    for(i = 0; i < m->chars->length; i++)
        printf("%c ", m->chars->array[i]);
    printf("\n");
    for(i = 0; i < m->chars->length; i++){
        printf("%c ", m->chars->array[i]);
        for(j = 0; j < m->chars->length; j++)
            printf("%i ", m->bits[i][j]);
        printf("\n");
    }
}