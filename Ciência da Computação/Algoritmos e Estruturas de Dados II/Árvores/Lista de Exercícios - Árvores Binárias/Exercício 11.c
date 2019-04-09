#include<stdio.h>
#include<stdlib.h>
#include<locale.h>

struct no
{
    int dado;
    struct no *dir;
    struct no *esq;
};


typedef struct no *Arvore;

void insertNode(Arvore *t,int p)
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
            printf("Memória insuficiente!\n");
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
                printf("Duplicação de nó!\n");
        }
    }
}

void PosFixa(Arvore A)
{
    if(A!=NULL)
    {
        PosFixa(A->esq);
        PosFixa(A->dir);
        printf("%d ",A->dado);
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
        int x;
        scanf("%d",&x);
        insertNode(&A,x);
    }
    printf("Deve se usar o percursso pos-fixo:\n");
    PosFixa(A);

}
