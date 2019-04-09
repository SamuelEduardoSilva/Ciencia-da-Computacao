
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


void buscaInter(Arvore A,Arvore B,Arvore *Intersecao)
{
    if(B != NULL)
    {
        if(A->dado == B->dado)
        {
            insertNode(&(*Intersecao),A->dado);
            return;
        }
        buscaInter(A,B->esq,&(*Intersecao));
        buscaInter(A,B->dir,&(*Intersecao));
    }
}

void geraIntersecao(Arvore A,Arvore B,Arvore *Intersecao)
{
    if(A != NULL)
    {
        buscaInter(A,B,&(*Intersecao));

        geraIntersecao(A->esq,B,&(*Intersecao));
        geraIntersecao(A->dir,B,&(*Intersecao));
    }
}

void imprime(Arvore t)
{
    if(t != NULL)
    {
        printf("%d ",t->dado);

        imprime(t->esq);
        imprime(t->dir);
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

    Arvore Intersecao = NULL;

    geraIntersecao(A,B,&Intersecao);

    printf("Árvore gerada a partir da intersecção das árvores A e B(pré-fixa):\n");
    imprime(Intersecao);

}
