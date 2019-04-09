#include<stdio.h>
#include<stdlib.h>


struct no
{
    int dado;
    struct no *prox;
    struct no *ant;

};

typedef struct
{

    struct no *inicio;
    struct no *fim;

}engrenagem;


void insert(engrenagem *q,int novo)
{
    struct no *aux;
    aux = (struct no*)malloc(sizeof(struct no));

    aux->dado = novo;


    if(q->inicio == NULL)
    {
        aux->dado = 1;
        q->inicio = aux;
        q->fim = aux;
        q->inicio->prox = aux;
        q->inicio->ant = aux;
        q->fim->prox = aux;
        q->fim->ant = aux;
    }
    else
    {
        q->fim->prox = aux;
        aux->ant = q->fim;
        q->fim  = aux;
        aux->prox = q->inicio;
        q->inicio->ant = aux;
    }

}

void create(engrenagem *q)
{
    q->inicio = NULL;
}

int size(engrenagem q)
{
    struct no *aux;
    aux = q.inicio;
    int cont = 0;

    if(aux!=q.fim)
    {
        do
        {
            cont++;
            aux = aux->prox;
        }while(aux != q.inicio);
    }
    else
        cont = 1;

 return cont;
}

void DoIt(engrenagem roda1,engrenagem roda2)
{
    struct no *aux1 = roda1.inicio;
    struct no *aux2 = roda2.inicio;

    printf("Roda 1 = %d | Roda 2 = %d\n",aux1->dado,aux2->dado);
    aux1 = aux1->prox;
    aux2 = aux2->ant;

    int giros1 = 0;
    int giros2 = 0;

    while(1)
    {

        printf("Roda 1 = %d | Roda 2 = %d\n",aux1->dado,aux2->dado);
        if(aux1==roda1.inicio && aux2 == roda2.inicio)
        {
            giros1++;
            giros2++;
            break;
        }
        if(aux1 == roda1.inicio)
            giros1++;
        if(aux2 == roda2.inicio)
            giros2++;

        aux1 = aux1->prox;
        aux2 = aux2->ant;

    }
    printf("Foram necessarios %d giros pra primeira roda!\n",giros1);
    printf("Foram necessarios %d giros pra segunda roda!\n",giros2);

}

int main()
{

   engrenagem roda1;
   engrenagem roda2;

   create(&roda1);
   create(&roda2);

   int i = 1;
   for(;i<=4;i++)
     insert(&roda1,i);

   i = 1;

   for(;i<=8;i++)
     insert(&roda2,i);

   DoIt(roda1,roda2);

}

