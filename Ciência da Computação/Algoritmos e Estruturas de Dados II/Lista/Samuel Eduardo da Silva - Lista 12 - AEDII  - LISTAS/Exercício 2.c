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

int isEmpty(lista q)
{
    if(q.inicio == NULL)
        return 1;
    return 0;
}

int insert(lista *q, int d)
{
        struct no *aux, *atual, *anterior;
        aux = (struct no *) malloc(sizeof(struct no));
        if (aux!=NULL)
        {
                aux->dado=d; aux->prox=NULL;
                anterior = NULL; atual = q->inicio;
                while (atual != NULL)
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
}
void imprime(lista q)
{
        struct no *aux;
        aux = q.inicio;
        if (!isEmpty(q))
        {
            while (aux != NULL)
            {
                printf("%d ", aux->dado);
                aux = aux->prox;
            }
        }
}




void concatena(lista l1,lista l2)
{
    struct no *aux1;


    aux1 = l2.inicio;

    while(aux1 != NULL)
    {
        insert(&l1,aux1->dado);
        aux1 = aux1->prox;
    }
}

int main()
{
    lista l1,l2;


    create(&l1);
    create(&l2);

    insert(&l1,1);
    insert(&l1,2);
    insert(&l1,3);
    insert(&l1,4);
    insert(&l1,5);


    insert(&l2,6);
    insert(&l2,7);
    insert(&l2,8);
    insert(&l2,9);
    insert(&l2,10);


    concatena(l1,l2);

    imprime(l1);

}
