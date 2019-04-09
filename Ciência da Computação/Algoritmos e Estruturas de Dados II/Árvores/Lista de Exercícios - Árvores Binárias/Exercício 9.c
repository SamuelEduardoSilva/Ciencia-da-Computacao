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

void menor(Arvore A,char *ans)
{
    if(A!=NULL)
    {
        if(A->dado < *ans)
            *ans = A->dado;
        menor(A->dir,ans);
        menor(A->esq,ans);
    }
}

int main()
{
    int t;
    Arvore A = NULL;
    Arvore B = NULL;
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

    char ans = A->dado;
    menor(A,&ans);
    printf("O menor elemento da lista é: %c\n",ans);
}
