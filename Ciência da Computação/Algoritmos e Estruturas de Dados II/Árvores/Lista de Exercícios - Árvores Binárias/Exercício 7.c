#include<stdio.h>
#include<stdlib.h>
#include<locale.h>

struct no
{
    char dado;
    struct no *dir;
    struct no *esq;
};


typedef struct no *Arvore;


void insertNode(Arvore *t,char p)
{
    if(*t == NULL)
    {
        *t = (struct no*)malloc(sizeof(struct no));
        if(*t != NULL)
        {
            (*t)->dir = NULL;
            (*t)->esq = NULL;
            (*t)->dado = p;
        }
        else
            printf("Mem�ria insuficiente!\n");
    }
    else
    {
        if((*t)->dado > p)
            insertNode(&(*t)->esq,p);
        else
        {
            if((*t)->dado < p)
                insertNode(&(*t)->dir,p);
            else
                printf("Duplica��o de n�!\n");
        }
    }
}

void show(Arvore t)
{
    if(t!=NULL)
    {
        printf("%c ",t->dado);
        show(t->esq);
        show(t->dir);
    }
}

void doit(Arvore t,char x)
{
    if(t!=NULL)
    {
        if(t->dado == x)
        {
            printf("Pr�-ordem da sub-�rvore � esquerda do elemento:\n");
            show(t->esq);
            return;
        }

        doit(t->dir,x);
        doit(t->esq,x);
    }
}

int main()
{
    int t;
    Arvore A = NULL;
    printf("Digite o numero de elementos que se deseja inserir na arvore: ");
    scanf("%d",&t);
    int i;

    setlocale(LC_ALL,"Portuguese");

    for(i=0;i<t;i++)
    {
        char x;
        scanf(" %c",&x);
        insertNode(&A,x);
    }

    char x;
    printf("Digite o elemento: ");
    scanf(" %c",&x);


    doit(A,x);


}
