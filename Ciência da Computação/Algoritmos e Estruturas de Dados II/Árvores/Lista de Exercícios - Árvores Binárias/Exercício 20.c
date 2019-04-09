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

int main()
{
    setlocale(LC_ALL,"Portuguese");

    Arvore A = NULL;

    int i;
    int x,n;
    int a,b;

    printf("Digite o n�mero de n�s que se deseja inserir na �rvore(m�x 100): ");

    scanf("%d",&n);

    printf("Insira aqui os n elementos:\n");
    for(i = 0;i < n; i++)
    {
        scanf("%d",&x);
        insertNode(&A,x);
    }
}
