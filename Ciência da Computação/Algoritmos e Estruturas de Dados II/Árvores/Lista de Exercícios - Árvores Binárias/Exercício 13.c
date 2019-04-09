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
int p,k,n;



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


int main()
{
    setlocale(LC_ALL,"Portuguese");

    Arvore A = NULL;
    int i;
    int x;
    int a,b;

    printf("Digite o número de nós que se deseja inserir na árvore(máx 100): ");

    scanf("%d",&n);

    printf("Insira aqui os n elementos:\n");
    for(i = 0;i < n; i++)
    {
        scanf("%d",&x);
        insertNode(&A,x);
    }

    printf("Digite o valor de a: ");
    scanf("%d",&a);
    printf("Digite o valor de b: ");
    scanf("%d",&b);
    printf("\nValores maiores que a e menores que b:\n");
    IT(A,a,b);
}
