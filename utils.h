#ifndef LIMITS_H
#define LIMITS_H
#include <limits.h>
#endif

#ifndef STDLIB_H
#define STDLIB_H
#include <stdlib.h>
#endif

typedef struct _array {
    char *array;
    unsigned int length;
} array;

array *get_unique_chars(char **connections) {
    array *a = malloc(sizeof(array));
    a->array = calloc(UCHAR_MAX, sizeof(char));
    int i, j, k, l = 0;
    for(i = 0; i < UCHAR_MAX; i++) a->array[i] = 0;
    for(i = 0; i < UCHAR_MAX; i++) {
        for(j = 0; j < 2; j++) {
            k = 0;
            while(a->array[k]
            && k < UCHAR_MAX) {
                if(a->array[k] == connections[i][j]) break;
                k++;
            }
            if(k < UCHAR_MAX
            && a->array[k] != connections[i][j]) {
                a->array[k] = connections[i][j];
                l++;
            }
        }
    }
    a->length = l;
    return a;
}

int get_char_index(char c, char *chars) {
    int i;
    for(i = 0; i < UCHAR_MAX; i++)
        if(chars[i] == c) return i;
    return -1;
}