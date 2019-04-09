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

void insertNode(Arvore *A,int d)
{
    if(*A == NULL)
    {
        *A = (struct no*)malloc(sizeof(struct no));

        if(*A != NULL)
        {
            (*A)->dado = d;
            (*A)->dir = NULL;
            (*A)->esq = NULL;
        }
        else
            printf("Memória insuficiente!\n");
    }
    else
    {
        if((*A)->dado < d)
            insertNode(&(*A)->dir,d);
        else
        {
            if((*A)->dado > d)
            {
                insertNode(&(*A)->esq,d);
            }
            else
                printf("Duplicação de nó!\n");
        }
    }
}

void doIt(Arvore a,int p)
{

    if(a!=NULL)
    {
        if(a->dado == p)
        {
            int flag1 = 0;
            int flag2 = 0;
            printf("Seu(s) sucessor(es) é/são: ");
            if(a->dir != NULL)
            {
                printf("%d ",a->dir->dado);
                flag1 = 1;
            }
            if(a->esq != NULL)
            {
                printf("%d ",a->esq->dado);
                flag2 = 1;
            }
            if(!flag1 && !flag2)
                printf("Esse elemento é um nó folha, portanto não tem sucessores!\n");

        }
        doIt(a->dir,p);
        doIt(a->esq,p);
    }
}

int main()
{
    Arvore tree = NULL;
    setlocale(LC_ALL,"Portuguese");

    printf("Digite o número de elementos se deseja inserir: ");
    int n,i,p;
    scanf("%d",&n);

    for(i = 0;i < n;i++)
    {
        int x;
        scanf("%d",&x);

        insertNode(&tree,x);
    }
    printf("Digite o valor do nó: ");
    scanf("%d",&p);

    doIt(tree,p);
}
