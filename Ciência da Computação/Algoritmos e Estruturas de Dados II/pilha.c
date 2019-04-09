#include<stdio.h>
#include<stdbool.h>
#include<stdlib.h>

struct no
{
    int dado;
    struct no *prox;
};

typedef struct
{
    struct no *topo;
}pilha;

void create(pilha *s)
{
    s -> topo = NULL;
}

int push(pilha *s,int d)
{
    struct no *aux;
    aux = (struct no *)malloc(sizeof(struct no));
    if(aux == NULL)
        return (0);
    aux -> dado = d;
    aux -> prox = s->topo;
    s -> topo = aux;
    return (1);
}

int top(pilha s)
{
    if(s.topo!=NULL)
       return s.topo->dado;
    return 0;
}

int pop(pilha *s)
{
    struct no *aux;
    if(s->topo == NULL)
        return 0;
    s -> topo = (s -> topo) -> prox;
    free(aux);
    return (1);
}

int size(pilha s)
{

    pilha pilhaAux = s;
    int cont  = 0;
    while(pilhaAux.topo != NULL)
    {
        pop(&pilhaAux);
        cont++;
    }
    return cont;
}

