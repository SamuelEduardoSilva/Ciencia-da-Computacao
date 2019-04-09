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
    struct no *atual;
    struct no *anterior;

    anterior = NULL;
    atual = q->inicio;


    aux = (struct no *)malloc(sizeof(struct no));

    aux -> dado = d;
    aux -> prox = NULL;

    while(atual!=NULL)
    {
        anterior = atual;
        atual = atual->prox;

    }
    if (anterior == NULL)
    {
            aux->prox = q->inicio;
            q->inicio = aux;
    }
    else
    {
            anterior->prox=aux;
            aux->prox = atual;
    }
}

void cria(lista origial,lista *pares,lista *impares)
{
    struct no *aux;
    aux = origial.inicio;

    while(aux!=NULL)
    {
        if(aux->dado % 2 == 0)
            insere(pares,aux->dado);
        else
            insere(impares,aux->dado);
        aux = aux->prox;
    }
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
     lista original;
     lista pares;
     lista impares;

     create(&original);
     create(&pares);
     create(&impares);

     insere(&original,1);
     insere(&original,2);
     insere(&original,3);
     insere(&original,4);
     insere(&original,5);
     insere(&original,6);
     insere(&original,7);
     insere(&original,8);
     insere(&original,9);
     insere(&original,10);

     cria(original,&pares,&impares);

     printf("Lista com os numeros pares:\n");
     ImprimeRecursivamente(pares.inicio);
     printf("\n");
     printf("Lista com os numeros impares:\n");
     ImprimeRecursivamente(impares.inicio);

}
