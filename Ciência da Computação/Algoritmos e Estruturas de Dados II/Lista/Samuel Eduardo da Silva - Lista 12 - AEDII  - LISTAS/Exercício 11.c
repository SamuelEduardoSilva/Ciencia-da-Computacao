#include<stdio.h>
#include<stdlib.h>
#include<locale.h>
struct no
{
    struct no *ant;
    struct no *prox;
    int dado;
};

typedef struct
{

    struct no *inicio;
    struct no *fim;

}lista;

void create(lista *q)
{
    q->inicio = NULL;
    q->fim = NULL;
}



void imprime(lista q)
{
    struct no *aux;
    aux = q.inicio;

    while(aux!=NULL)
    {
        printf("%d ",aux->dado);
        aux = aux->prox;
    }
    printf("\n");
}


void inserir(lista *q,int d)
{
    struct no *aux;
    struct no *anterior;
    struct no *atual;

    aux = (struct no*)malloc(sizeof(struct no));
    aux -> dado = d;

    if(q->inicio == NULL)
    {
        aux -> ant =NULL;
        aux -> prox = NULL;
        q->inicio = aux;
        q->fim = aux;
        return;
    }
    aux->prox = NULL;
    aux->ant = q->fim;
    q->fim->prox = aux;
    q->fim = aux;
}


void concatena(lista *a,lista b)
{
    struct no *aux;

    aux = b.inicio;

    while(aux!=NULL)
    {
        inserir(a,aux->dado);
        aux = aux->prox;
    }
}
int main()
{
    setlocale(LC_ALL,"Portuguese");

    lista a;
    lista b;

    create(&a);
    create(&b);

    inserir(&a,1);
    inserir(&a,2);
    inserir(&a,3);
    inserir(&a,4);
    inserir(&a,5);

    inserir(&b,6);
    inserir(&b,7);
    inserir(&b,8);
    inserir(&b,9);
    inserir(&b,10);

    concatena(&a,b);

    printf("Lista B concatenada em A: ");
    imprime(a);

}

