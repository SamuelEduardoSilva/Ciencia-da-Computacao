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
           // else
             //   printf("Duplicação de nó!\n");
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

void imprime(Arvore t)
{
    if(t != NULL)
    {
        printf("%d ",t->dado);

        imprime(t->esq);
        imprime(t->dir);
    }
}

void IT(Arvore A,int a,int b)
{
    if(A != NULL)
    {
        if(A->dado > a && A->dado < b)
           printf("%d ",A->dado);

        IT(A->esq,a,b);
        IT(A->dir,a,b);
    }
}

void geraVetorMediana(int *mediana,Arvore R,int *a)
{
    if(R != NULL)
    {
        geraVetorMediana(&(*mediana),R->esq,&(*a));
        mediana[(*a)++] = R->dado;
        geraVetorMediana(&(*mediana),R->dir,&(*a));
    }
}

int size(Arvore R)
{
    if(R == NULL)
        return 0;

    return size(R->esq)+size(R->dir)+1;

}

int main()
{
     setlocale(LC_ALL,"Portuguese");

    Arvore A = NULL;
    Arvore B = NULL;
    Arvore C = NULL;
    Arvore R = NULL;

    int i;
    int x,n;
    int a,b;

    printf("Digite o número de nós que se deseja inserir na árvore A: ");

    scanf("%d",&n);

    printf("Insira aqui os n elementos:\n");
    for(i = 0;i < n; i++)
    {
        scanf("%d",&x);
        insertNode(&A,x);
    }

    printf("Digite o número de nós que se deseja inserir na árvore B: ");

    scanf("%d",&n);

    printf("Insira aqui os n elementos:\n");
    for(i = 0;i < n; i++)
    {
        scanf("%d",&x);
        insertNode(&B,x);
    }

    printf("Digite o número de nós que se deseja inserir na árvore C: ");

    scanf("%d",&n);

    printf("Insira aqui os n elementos:\n");
    for(i = 0;i < n; i++)
    {
        scanf("%d",&x);
        insertNode(&C,x);
    }

    geraIntersecao(B,C,&R);
    geraUniao(&R,A,R);


    printf("\n\nÁrvore gerada apartir da intersecção de B e C, unida a A:\n");
    imprime(R);

    printf("\n\nDigite o valor de valor1 e de valor2:\n");
    int valor1,valor2;
    scanf("%d %d",&valor1,&valor2);

    printf("Os elementos que estão entre %d e %d, são:\n",valor1,valor2);
    IT(R,valor1,valor2);


    int v = size(R);
    int q = 0;
    int mediana[v];
    geraVetorMediana(mediana,R,&q);

    printf("\nA mediana dessa Árvore é : %d\n",mediana[(v+1)/2]);



}
