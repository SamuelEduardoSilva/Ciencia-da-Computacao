
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
            printf("Mem�ria insuficiente!\n");
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
                printf("Duplica��o de n�!\n");
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

    printf("Digite o n�mero de n�s que se deseja inserir na primeira �rvore(m�x 100): ");

    scanf("%d",&n);

    printf("Insira aqui os n elementos:\n");
    for(i = 0;i < n; i++)
    {
        scanf("%d",&x);
        insertNode(&A,x);
    }

    printf("Digite o n�mero de n�s que se deseja inserir na segunda �rvore(m�x 100): ");

    scanf("%d",&n);

    printf("Insira aqui os n elementos:\n");
    for(i = 0;i < n; i++)
    {
        scanf("%d",&x);
        insertNode(&B,x);
    }

    Arvore Intersecao = NULL;

    geraIntersecao(A,B,&Intersecao);

    printf("�rvore gerada a partir da intersec��o das �rvores A e B(pr�-fixa):\n");
    imprime(Intersecao);

}
