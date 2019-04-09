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

void busca(lista q,int procurado)
{
    struct no *aux;
    aux = q.inicio;

    while(aux!=NULL)
    {
        if(aux->dado == procurado)
        {
            printf("Elemento encontrado na lista!\n");
            return;
        }
        aux = aux->prox;
    }
    printf("Elemento não encontrado!\n");
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

int contagem(lista q)
{
    struct no *aux;
    aux = q.inicio;
    int cont = 0;

    while(aux!=NULL)
    {
        cont++;
        aux = aux->prox;
    }
    return cont;
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

void remover(lista *q,int x)
{
    struct no *aux;
    struct no *anterior;
    struct no *atual;

    if(q->inicio->dado == x)
    {
        aux = q->inicio;
        if(q->inicio->prox == NULL)
        {
            q->inicio = NULL;
            q->fim = NULL;
        }
        else
        {
            q->inicio = aux->prox;
            q->inicio->ant = aux->ant;
        }
        free(aux);
        return;
    }
    anterior = q->inicio;
    atual = anterior->prox;

    while(atual != NULL && atual->dado != x)
    {
        anterior = atual;
        atual = atual->prox;
    }

     if(q->fim == atual)
     {
         aux = atual;
         q->fim = atual->ant;
         atual->ant->prox = q->fim;
         q->fim->prox = NULL;
         free(aux);
         return;

     }
    if(atual != NULL)
    {
        aux = atual;
        anterior -> prox = atual->prox;
        atual->prox->ant = anterior;
        if(atual -> prox == NULL)
        {
            anterior -> prox = NULL;
            q->fim = anterior;
        }
        free(aux);
    }
    else
        printf("Elemento não está na lista!\n");
}

int main()
{
    setlocale(LC_ALL,"Portuguese");



}
