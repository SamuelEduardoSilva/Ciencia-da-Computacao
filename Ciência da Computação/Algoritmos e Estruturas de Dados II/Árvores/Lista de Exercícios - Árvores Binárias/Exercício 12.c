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

int flag = 0;

void checkNoFolha(Arvore *A,int d)
{
    if(*A!=NULL)
    {
        if((*A)->dado == d)
        {
            if((*A)->dir == NULL && (*A)->esq ==NULL)
            {
                (*A) = NULL;
                flag = 1;
                return;
            }

        }
        checkNoFolha(&(*A)->dir,d);
        checkNoFolha(&(*A)->esq,d);
    }
}
void preOrder(Arvore t)
{
      if (t != NULL)
      {
            printf("%d ", t->dado);
            preOrder(t->esq);
            preOrder(t->dir);
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

    printf("Para o n� 8:\n");
    flag = 0;
    checkNoFolha(&A,8);
    if(!flag)
        printf("Impossivel a remo��o do n� 7, pois ele � um n� folha!\n");
    else
    {
        printf("Possivel de remo��o por  8 n�o ser um n� folha!\n");
        printf("Percurso pr�-fixo sem esse n�:\n");
        preOrder(A);
    }
    flag = 0;
    printf("Para o n� 7:\n");
    checkNoFolha(&A,7);

    if(!flag)
        printf("Impossivel a remo��o do n� 7, pois ele � um n� folha!\n");
    else
    {
        printf("Possivel de remo��o por n�o  7 ser um n� folha!\n");
        printf("Percurso pr�-fixo sem esse n�:\n");
        preOrder(A);
    }

    flag = 0;
    printf("Para o n� 9:\n");
    checkNoFolha(&A,9);

    if(!flag)
      printf("Impossivel a remo��o do n� 9, pois ele � um n� folha!\n");
    else
    {
        printf("Possivel de remo��o por 9 n�o ser um n� folha!\n");
        printf("Percurso pr�-fixo sem esse n�:\n");
        preOrder(A);
    }
}
