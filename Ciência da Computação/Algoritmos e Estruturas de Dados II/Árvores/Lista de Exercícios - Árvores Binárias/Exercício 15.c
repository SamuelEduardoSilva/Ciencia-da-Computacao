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

void InsereDeArvoreX(Arvore *Uniao,Arvore X)
{
    if(X != NULL)
    {
        insertNode(&(*Uniao),X->dado);
        InsereDeArvoreX(&(*Uniao),X->esq);
        InsereDeArvoreX(&(*Uniao),X->dir);
    }
}

void geraUniao(Arvore *Uniao,Arvore A,Arvore B)
{
    InsereDeArvoreX(&(*Uniao),A);
    InsereDeArvoreX(&(*Uniao),B);
}

void imprime(Arvore A)
{
    if(A != NULL)
    {
        imprime(A->esq);
        printf("%d ",A->dado);
        imprime(A->dir);
    }
}

int main()
{
    setlocale(LC_ALL,"Portuguese");

    Arvore A = NULL;
    Arvore B = NULL;
    int i;
    int x,n;
    int a,b;

    printf("Digite o número de nós que se deseja inserir na primeira árvore(máx 100): ");

    scanf("%d",&n);

    printf("Insira aqui os n elementos:\n");
    for(i = 0;i < n; i++)
    {
        scanf("%d",&x);
        insertNode(&A,x);
    }

    printf("Digite o número de nós que se deseja inserir na segunda árvore(máx 100): ");

    scanf("%d",&n);

    printf("Insira aqui os n elementos:\n");
    for(i = 0;i < n; i++)
    {
        scanf("%d",&x);
        insertNode(&B,x);
    }

    Arvore Uniao = NULL;

    geraUniao(&Uniao,A,B);


    printf("Arvore união gerada a partir de A e B(infixa):\n");
    imprime(Uniao);
}
