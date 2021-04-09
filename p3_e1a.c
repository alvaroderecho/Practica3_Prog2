#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "delivery.h"
#include "product.h"
#include "types.h"

#define FAIL 1
#define WORD_LENGHT 64
#define MAX_VERTEX 16

Delivery *build_delivery(FILE *pf);

int main(int argc, char *argv[])
{
    Delivery *delv;
    FILE *pf;
    int i;
    Queue * qu;
    size_t size;

    if (argc != 2)
    {
        printf("Wrong number of arguments.\n");
        return FAIL;
    }

    if ((pf = fopen(argv[1], "r")) == NULL)
        return FAIL;

    delv = build_delivery(pf);

    if (delivery_run_plan(stdout, delv) == ERROR)
    {
        delivery_free(delv);
        fclose(pf);
        return FAIL;
    }
    qu = delivery_getPlan(delv);
    size = queue_size(qu);
    for (i=0;i<size;i++) {
        product_free(queue_pop(qu));
    }

    delivery_free(delv);
    fclose(pf);
    return 0;
}

Status delivery_add(Delivery *d, Product *p)
{

    if (!d || !p)
        return ERROR;

    if (queue_push(delivery_getPlan(d), p) == ERROR)
        return ERROR;

    return OK;
}

Status delivery_run_plan(FILE *pf, Delivery *d)
{
    size_t size;
    int i;
    Delivery *delv;
    Queue *cola;
    const Vertex *ver;

    if (!d)
        return ERROR;

    delv = delivery_copy(d);

    cola = delivery_getPlan(delv);
    if (!cola)
        return ERROR;
    size = queue_size(cola);

    for (i = 0; i < size; i++)
    {
        ver = product_getVertex(queue_pop(cola));
        fprintf(pf, "Delivering %s requested by %s to %s.\n", delivery_getProductName(d), delivery_getName(d), vertex_getTag(ver));
        
    }

    delivery_free(delv);
    return OK;
}

Delivery *build_delivery(FILE *pf)
{
    Delivery *dev;
    char del_name[WORD_LENGHT], desc[WORD_LENGHT];
    char prod_name[WORD_LENGHT];
    int capac, num_ciu, i, amm, j;
    Vertex *v[MAX_VERTEX];
    Product *pr[MAX_VERTEX];

    if (!pf)
        return NULL;

    fscanf(pf, "%s %s %d\n", del_name, prod_name, &capac);

    if ((dev = delivery_init(del_name, prod_name)) == NULL)
        return NULL;

    if (delivery_setCapacity(dev, capac) == ERROR)
    {
        delivery_free(dev);
        return NULL;
    }

    fscanf(pf, "%d\n", &num_ciu);

    for (i = 0; i < num_ciu; i++)
    {
        fscanf(pf, "%d\n", &amm);
        fgets(desc, 32, pf);

        if ((v[i] = vertex_initFromString(desc)) == NULL)
        {
            for (j = 0; j < i; j++)
            {
                product_free(pr[j]);
            }
            delivery_free(dev);
            return NULL;
        }
        if ((pr[i] = product_init(v[i])) == NULL)
        {
            for (j = 0; j < i; j++)
            {
                product_free(pr[j]);
            }
            delivery_free(dev);
            return NULL;
        }
        if (product_setAmount(pr[i], amm) == ERROR)
        {
            for (j = 0; j < i; j++)
            {
                product_free(pr[j]);
            }
            delivery_free(dev);
            return NULL;
        }
        if (delivery_add(dev, pr[i]) == ERROR)
        {
            for (j = 0; j < i; j++)
            {
                product_free(pr[j]);
            }
            delivery_free(dev);
            return NULL;
        }
    }

    return dev;
}