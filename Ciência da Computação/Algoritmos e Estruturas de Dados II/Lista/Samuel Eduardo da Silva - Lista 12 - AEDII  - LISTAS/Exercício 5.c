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

void removerX(lista *q,int x)
{
     struct no *atual;
     struct no *anterior;
     struct no *aux;
     int continua = 1;

     while(continua)
     {
         continua = 0;
         if (x == (q->inicio)->dado)
         {
            aux = q->inicio;
            q->inicio = (q->inicio)->prox;
            free(aux);
            continua = 1;
         }
         else
         {
            anterior = q->inicio;
            atual = (q->inicio)->prox;
            while (atual != NULL && atual->dado != x)
            {
                anterior = atual;
                atual = atual->prox;
            }
            if (atual != NULL)
            {
                aux = atual;
                anterior->prox = atual->prox;
                free(aux);
                continua = 1;
            }
        }
     }
}
int main()
{
    lista x;

    create(&x);

    insere(&x,1);
    insere(&x,2);
    insere(&x,4);
    insere(&x,4);
    insere(&x,5);
    insere(&x,6);
    insere(&x,7);

    int a;
    printf("Digite o valor de x: ");
    scanf("%d",&a);

    removerX(&x,a);

    ImprimeRecursivamente(x.inicio);
}
