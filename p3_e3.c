#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "vertex.h"
#include "list.h"
#define MAX_VERTEX 10
#define MAX_STRING 100
int main (int argc, char *argv[]){

    FILE *pf;
    char aux[MAX_STRING];
    int num_v,i;
    void *e;
    Vertex *v[MAX_VERTEX],*v_aux[MAX_VERTEX];
    List *pl;
    pf = fopen(argv[1],"r");
    fscanf(pf,"%d\n",&num_v);

    for (i=0;i<num_v;i++){
        fgets(aux,64,pf);
        v[i] = vertex_initFromString(aux);
        vertex_print(stdout,v[i]);
    }
    printf ("\n");
    
    fclose(pf);
   
    pl = list_new();
     
    for (i=0;i<num_v;i++){
        e=v[i];
        vertex_free(v[i]);
        
    if (list_pushFront(pl,e) == ERROR ) return -1;
    
    }
    printf("Finished inserting. Now we stract from the begining.\n");
    for (i=0;i<(num_v/2);i++){
        
        v_aux[i] = list_popFront(pl);
        vertex_print(stdout,v_aux[i]);
        vertex_free(v_aux[i]);
    }
    printf("\nNow we stract from the end.");
    for (;i<num_v;i++){
        v_aux[i] = list_popBack(pl);
        vertex_print(stdout,v_aux[i]);
        vertex_free(v_aux[i]);
    }
return 0;
}