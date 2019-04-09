#include<stdio.h>
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

void ImprimeRecursivamente(struct no *q)
{
    if(q == NULL)
        return;
    printf("%d ",q->dado);
    ImprimeRecursivamente(q->prox);
}

int main()
{
    lista x;

    create(&x);

    insere(&x,1);
    insere(&x,2);
    insere(&x,3);
    insere(&x,4);
    insere(&x,5);
    insere(&x,6);
    insere(&x,7);


    ImprimeRecursivamente(x.inicio);

}
