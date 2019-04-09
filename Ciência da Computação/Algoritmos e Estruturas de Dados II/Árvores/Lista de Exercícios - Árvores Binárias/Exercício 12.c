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

    printf("Para o nó 8:\n");
    flag = 0;
    checkNoFolha(&A,8);
    if(!flag)
        printf("Impossivel a remoção do nó 7, pois ele é um nó folha!\n");
    else
    {
        printf("Possivel de remoção por  8 não ser um nó folha!\n");
        printf("Percurso pré-fixo sem esse nó:\n");
        preOrder(A);
    }
    flag = 0;
    printf("Para o nó 7:\n");
    checkNoFolha(&A,7);

    if(!flag)
        printf("Impossivel a remoção do nó 7, pois ele é um nó folha!\n");
    else
    {
        printf("Possivel de remoção por não  7 ser um nó folha!\n");
        printf("Percurso pré-fixo sem esse nó:\n");
        preOrder(A);
    }

    flag = 0;
    printf("Para o nó 9:\n");
    checkNoFolha(&A,9);

    if(!flag)
      printf("Impossivel a remoção do nó 9, pois ele é um nó folha!\n");
    else
    {
        printf("Possivel de remoção por 9 não ser um nó folha!\n");
        printf("Percurso pré-fixo sem esse nó:\n");
        preOrder(A);
    }
}
