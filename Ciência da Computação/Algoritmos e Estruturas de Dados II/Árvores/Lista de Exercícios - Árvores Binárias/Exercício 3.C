#include<stdio.h>
#include<stdlib.h>


struct no
{
    struct no *esq;
    struct no *dir;
    char dado;
};

typedef struct no *Arvore;

void insertNode(Arvore *t, char d)
{
        if (*t == NULL)
        {
            *t = (struct no*) malloc(sizeof(struct no));
            if ( *t != NULL )
            {
                (*t)->esq = NULL;
                (*t)->dir = NULL;
                (*t)->dado = d;
            }
            else
                printf("Memoria insuficiente");
        }
        else
        {
           if (d < (*t)->dado)
              insertNode(&(*t)->esq, d);
           else
           {
               if (d > (*t)->dado)
                 insertNode(&(*t)->dir, d);
               else
                 printf("Duplicação de no");
           }
        }
}

void showonesub(Arvore t)
{
     if(t != NULL)
     {
         if((t->dir != NULL && t->esq==NULL) ||(t->dir == NULL && t->esq != NULL))
            printf("%c ",t->dado);
         showonesub(t->dir);
         showonesub(t->esq);

     }
}

int main()
{
    int t;
    Arvore A = NULL;
    printf("Digite o numero de elementos que se deseja inserir na arvore: ");
    scanf("%d",&t);
    int i;

    for(i=0;i<t;i++)
    {
        char x;
        scanf(" %c",&x);
        insertNode(&A,x);
    }
    showonesub(A);
}
