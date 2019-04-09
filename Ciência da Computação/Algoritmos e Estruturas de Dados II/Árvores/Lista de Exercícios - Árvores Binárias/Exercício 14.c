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

void doIt(Arvore *A,int p,int o)
{
    if((*A) != NULL)
    {

        if((*A)->dado == p)
            (*A)->dado = o;

        doIt(&(*A)->esq,p,o);
        doIt(&(*A)->dir,p,o);
    }
}

imprime(Arvore A)
{
    if(A != NULL)
    {

        imprime(A->dir);
        printf("%d ",A->dado);
        imprime(A->esq);
    }
}

int main()
{
    setlocale(LC_ALL,"Portuguese");

    Arvore A = NULL;
    int i;
    int x,n;
    int a,b;

    printf("Digite o número de nós que se deseja inserir na árvore(máx 100): ");

    scanf("%d",&n);

    printf("Insira aqui os n elementos:\n");
    for(i = 0;i < n; i++)
    {
        scanf("%d",&x);
        insertNode(&A,x);
    }

    printf("Digite o valor que se deseja atualizar: ");
    int p;
    scanf("%d",&p);
    int o;
    printf("Digite qual deve ser o novo valor do nó: ");
    scanf("%d",&o);

    doIt(&A,p,o);

    printf("Árvore após sua atualização (infixa):\n");
    imprime(A);
}
