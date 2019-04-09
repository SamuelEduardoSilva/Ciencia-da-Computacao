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

void nos2Subs(Arvore A)
{
    if(A != NULL)
    {
        if(A->dir != NULL && A->esq != NULL)
           printf("%c ",A->dado);

        nos2Subs(A->dir);
        nos2Subs(A->esq);
    }
}

int main()
{
    Arvore A = NULL;


    insertNode(&A,'5');
    insertNode(&A,'7');
    insertNode(&A,'9');
    insertNode(&A,'1');
    insertNode(&A,'2');
    insertNode(&A,'6');
    insertNode(&A,'3');
    insertNode(&A,'8');
    insertNode(&A,'4');


    nos2Subs(A);

}
