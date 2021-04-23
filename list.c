#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "list.h"
typedef struct _Nodelist
{
    void *data;
    struct _NodeList *next;

} NodeList;

struct _List
{
    NodeList *last;
};
NodeList *node_new();
NodeList *node_new()
{
    NodeList *pn = NULL;

    pn = (NodeList *)malloc(sizeof(NodeList));
    if (!pn)
        return NULL;
    pn->next = NULL;
    pn->data = NULL;

    return pn;
}
List *list_new()
{
    List *pl;

    pl = (List *)malloc(sizeof(List));

    if (pl == NULL)
        return NULL;

    pl->last = NULL;

    return pl;
}

Bool list_isEmpty(const List *pl)
{
    if (pl == NULL)
        return TRUE;

    if (pl->last->next == NULL)
        return TRUE;

    return FALSE;
}

Status list_pushFront(List *pl, void *e)
{

    NodeList *pn;

    if (pl == NULL || e == NULL)
        return ERROR;

    pn = node_new();

    if (pn == NULL)
        return ERROR;

    pn->data = e;
    if (list_isEmpty(pl) == TRUE)
    {
        pn->next = pn;
        pl->last = pn;
    }
    else
    {
        pn->next = pl->last->next;
        pl->last->next = pn;
    }
    return OK;
}
Status list_pushBack(List *pl, void *e)
{
    NodeList *pn;

    if (pl == NULL || e == NULL)
        return ERROR;

    pn = node_new();

    if (pn == NULL)
        return ERROR;

    pn->data = e;
    if (list_isEmpty(pl) == TRUE)
    {
        pn->next = pn;
        pl->last = pn;
    }
    else
    {
        pn->next = pl->last->next;
        pl->last->next = pn;
        pl->last = pn;
    }
    return OK;
}
Status list_pushInOrder(List *pl, void *e, P_ele_cmp f, int order)
{

}
void *list_popFront(List *pl)
{
    NodeList *pn = NULL;
    void *pe = NULL;
    if (pl == NULL || list_isEmpty(pl) == TRUE)
    {
        return NULL;
    }
    pn = pl->last->next;
    pe = pn->data;
    if (pl->last->next == pl->last)
    {
        pl->last = NULL;
    }
    else
    {
        pl->last->next = pn->next;
    }
    free(pn);
    return pe;
}
void *list_popBack(List *pl)
{
    NodeList *pn = NULL;
    void *pe = NULL;
    if (pl == NULL || list_isEmpty(pl) == TRUE)
    {
        return NULL;
    }
    if (pl->last->next == pl->last)
    {
        pe = pl->last->data;
        free(pl->last);
        pl->last = NULL;
        return pe;
    }
    pn = pl->last;
    while (pn->next != pl->last)
    {
        pn = pn->next;
    }
    pe = pl->last->data;
    pn->next = pl->last->next;
    free(pl->last);
    pl->last = pn;
    return pe;
}
void list_free(List *pl){
    if (pl == NULL) return;
    free(pl);
}
size_t list_size(const List *pl){

}
int list_print(FILE *fp, const List *pl, P_ele_print f){

}