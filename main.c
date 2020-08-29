/* Faça um programa que receba o nome de um arquivo .csv e monte uma matriz de adjacências e uma lista de adjacências.

O arquivo irá conter N linhas, cada linha com a identificação de 2 vértices separados por ";". */
#ifndef STDLIB_H
#define STDLIB_H
#include <stdlib.h>
#endif

#ifndef STDIO_H
#define STDIO_H
#include <stdio.h>
#endif

#ifndef LIMITS_H
#define LIMITS_H
#include <limits.h>
#endif

#ifndef LIST_H
#define LIST_H
#include "list.h"
#endif

#ifndef MATRIX_H
#define MATRIX_H
#include "matrix.h"
#endif

#define BUFFER_SIZE 16

char **get_connections(char *filename) {
    FILE *f = fopen(filename, "r");
    char buffer[BUFFER_SIZE] = { 0 };
    int i, size;

    char **connections = malloc(sizeof(char*) * UCHAR_MAX);
    for(i = 0; i < UCHAR_MAX; i++)
        connections[i] = calloc(sizeof(char), 2);

    while(fgets(buffer, sizeof buffer, f) != NULL) {
        int flag = 0;
        char a = 0, b = 0;
        for(i = 0; i < sizeof buffer; i++) {
            if ((buffer[i] >= 'a' && buffer[i] <= 'z')
            || (buffer[i] >= 'A' && buffer[i] <= 'Z')
            || (buffer[i] >= '0' && buffer[i] <= '9')) {
                if(flag == 0) a = buffer[i];
                else b = buffer[i];
            }
            if(buffer[i] == ';') flag = 1;
            if(buffer[i] == '\n'
            || buffer[i] == '\0') {
                if(a && b) {
                    int j = 0;
                    while(connections[j][0]
                    && connections[j][1]) j++;
                    if(j < UCHAR_MAX) {
                        connections[j][0] = a;
                        connections[j][1] = b;
                    }
                }
                break;
            }
        }
    }

    fclose(f);

    sort_matrix(connections, UCHAR_MAX);

    return connections;
}

int main(int argc, char *argv[]) {
    char **connections = get_connections(argv[1]);
    list *g = new_list(connections);
    print_list(g);
    printf("\n");
    print_dfs(g);
    printf("\n");
    matrix *m = new_matrix(connections);
    print_matrix(m);
}