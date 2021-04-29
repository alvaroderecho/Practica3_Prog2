#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "vertex.h"
#include "list.h"
#define MAX_VERTEX 10
#define MAX_STRING 100
#define FAIL -1
int main(int argc, char *argv[])
{

    FILE *pf;
    char aux[MAX_STRING] = "";
    int num_v, i,j;
    Vertex *v[MAX_VERTEX], *v_aux[MAX_VERTEX];
    List *pl;

    if (argc != 2)
    {
        printf("Wrong number of input arguments.\n");
        return FAIL;
    }

    if (strcmp(argv[1], "g2.txt"))
    {
        printf("Error opening file: %s\n",argv[1]);
        return FAIL;
    }
    pf = fopen(argv[1], "r");
    if (pf == NULL) {
        printf("Error opening file: %s\n",argv[1]);
        return FAIL;
    }
    fscanf(pf, "%d\n", &num_v);

    for (i=0;i<MAX_VERTEX;i++) {
        v[i] = NULL;
        v_aux[i] = NULL;
    }

    for (i = 0; i < num_v; i++)
    {
        fgets(aux, 64, pf);
        v[i] = vertex_initFromString(aux);
        vertex_print(stdout, v[i]);
    }
    printf("\n");

    fclose(pf);

    pl = list_new();
    if (pl == NULL) {
        printf("Error creating new list.");
        for (i=0;i<num_v;i++) {
            vertex_free(v[i]);
        }
        fclose(pf);
        return FAIL;
    }

    for (i = 0; i < num_v; i++)
    {
        if (list_pushFront(pl, v[i]) == ERROR){
            printf("Error in list pushing elements.");
            for (j=i;j<num_v;j++) {
                vertex_free(v[j]);
            }
            list_free(pl);
            fclose(pf);
            return FAIL;
        }
    }
    printf("Finished inserting. Now we stract from the begining:\n");
    for (i = 0; i < (num_v / 2) + 1; i++)
    {
        v_aux[i] = list_popBack(pl);
        vertex_print(stdout, v_aux[i]);
    }
    printf("\nNow we stract from the end:\n");
    for (; i < num_v; i++)
    {
        v_aux[i] = list_popFront(pl);
        vertex_print(stdout, v_aux[i]);
    }
    for (i=0;i<num_v;i++) {
        vertex_free(v[i]);
    }
    printf("\n");

    list_free(pl);
    return 0;
}