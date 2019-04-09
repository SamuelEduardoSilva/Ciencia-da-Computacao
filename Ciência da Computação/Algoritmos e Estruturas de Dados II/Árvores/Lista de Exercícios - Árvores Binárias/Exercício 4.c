#include<stdio.h>
#include<stdlib.h>

struct no
{
    struct no *esq;
    struct no *dir;
    int dado;
};

typedef struct no *Arvore;
void insertNode(Arvore *t,int d)
{
    if(*t == NULL)
    {
         *t = (struct no*)malloc(sizeof(struct no));
        (*t)->dado = d;
        (*t)->esq = NULL;
        (*t)->dir = NULL;
    }
    else
    {
        if((*t)->dado > d)
            insertNode(&(*t)->esq,d);
        else
        {
            if((*t)->dado < d)
                insertNode(&(*t)->dir,d);
            else
                printf("Duplicação de nó!\n");
        }
    }
}

void MostraFolhas(Arvore T)
{
    if(T != NULL)
    {
        if(T -> esq == NULL && T->dir == NULL)
            printf("%d ",T->dado);

        MostraFolhas(T->esq);
        MostraFolhas(T->dir);
    }
}

int main()
{
    Arvore A = NULL;
    insertNode(&A,1);
    insertNode(&A,2);
    insertNode(&A,3);
    insertNode(&A,4);
    insertNode(&A,5);
    insertNode(&A,6);
    insertNode(&A,7);
    insertNode(&A,8);

    MostraFolhas(A);
}
