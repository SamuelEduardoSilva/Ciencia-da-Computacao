#include<stdio.h>
#include<stdlib.h>
#include<locale.h>

struct no
{
    int dado;
    struct no *esq;
    struct no *dir;
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
int flag = 0;
void removeNode(Arvore *A,int t)
{

    if(*A != NULL)
    {


        removeNode(&(*A)->esq,t);
        removeNode(&(*A)->dir,t);

        if((*A)->dir != NULL && (*A)->dir->dado == t)
        {

           if((*A)->dir->dir == NULL && (*A)->dir->esq == NULL)
           {
               free((*A)->dir);
               (*A)->dir = NULL;

               flag = 1;
               printf("N� removido com sucesso!\n");
               return;
           }
           else
           {

                flag = 1;
                printf("O n� desejado n�o � folha!\n");
                return;
           }
        }
        else if((*A)->esq != NULL &&(*A)->esq->dado == t)
        {

           if((*A)->esq->dir == NULL && (*A)->esq->esq == NULL)
           {

               flag = 1;
               free((*A)->esq);
               (*A)->esq = NULL;

               printf("N� removido com sucesso!\n");
               return;
           }
           else
           {

                flag = 1;
                printf("O n� desejado n�o � folha!\n");
                return;
           }
        }
    }
}

int main()
{
    Arvore A = NULL;


    int i;
    int x,n;
    int a,b;
    setlocale(LC_ALL,"Portuguese");

    printf("Digite o n�mero de n�s que se deseja inserir �rvore (valor m�x = 100): ");

    scanf("%d",&n);


    printf("Insira aqui os n elementos (valor m�x = 100 / valor min = 1):\n");
    for(i = 0;i < n; i++)
    {
        scanf("%d",&x);
        insertNode(&A,x);
    }

    while(1)
    {

        printf("Digite o elemento que se deseja remover:\n(Podendo apenas estar na �rvore e ser um n� folha!)\n");
        printf("-> -1 para sair do programa.\n");



        int t;
        scanf("%d",&t);

        if(t == -1)
            break;
        flag = 0;
        removeNode(&A,t);


        if(!flag)
            printf("O n� desejado n�o existe na �rvore!\n");
    }
}
