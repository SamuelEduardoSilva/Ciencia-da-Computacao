#include<stdlib.h>
#include<stdlib.h>

struct no
{
    int dado;
    struct no *prox;
};


typedef struct
{
    struct no *inicio;
}lista;

void create(lista *q)
{
    q->inicio = NULL;
}

void insere(lista *q,int d)
{
    struct no *aux;
    aux = (struct no *)malloc(sizeof(struct no));

    aux->dado = d;
    aux->prox = q->inicio;
    q->inicio = aux;

}
int size(lista q)
{
    struct no *aux;
    aux = q.inicio;
    int cont = 0;

    if(aux == NULL)
        return 0;
    while(aux!=NULL)
    {
        cont++;
        aux = aux->prox;
    }
    return cont;
}

int main()
{
    lista x;
    create(&x);

    insere(&x,1);
    insere(&x,1);
    insere(&x,1);
    insere(&x,1);
    insere(&x,1);
    insere(&x,1);
    insere(&x,1);
    insere(&x,1);
    insere(&x,1);

    printf("A lista tem %d elementos!\n",size(x));
}
