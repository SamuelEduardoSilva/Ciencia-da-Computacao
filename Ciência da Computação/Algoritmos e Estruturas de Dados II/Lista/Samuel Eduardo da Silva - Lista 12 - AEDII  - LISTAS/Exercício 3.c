#include<stdio.h>
#include<stdlib.h>

struct no
{ int dado;
  struct no *prox;

};
typedef struct
{
     struct no *inicio;

} lista;

void create(lista *q)
{
        q->inicio=NULL;
}

int insert(lista *q, int d)
{
        struct no *aux, *atual, *anterior;
        aux = (struct no *) malloc(sizeof(struct no));

        aux->dado=d;

        aux->prox = q->inicio;
        q->inicio = aux;

}




void inverte(lista *q)
{

   lista aux;

   struct no *x;
   x = q->inicio;

   create(&aux);

   while(x!=NULL)
   {
       insert(&aux,x->dado);
       x = x->prox;
   }

   *q = aux;

}


void imprime(lista q)
{
    struct no *aux;
    aux = q.inicio;

    while(aux != NULL)
    {
        printf("%d ",aux->dado);
        aux = aux->prox;
    }
}

int main()
{
    lista q;
    create(&q);

    insert(&q,1);
    insert(&q,2);
    insert(&q,3);
    insert(&q,4);
    insert(&q,5);
    insert(&q,6);
    insert(&q,7);
    insert(&q,8);

    inverte(&q);
    imprime(q);


}


