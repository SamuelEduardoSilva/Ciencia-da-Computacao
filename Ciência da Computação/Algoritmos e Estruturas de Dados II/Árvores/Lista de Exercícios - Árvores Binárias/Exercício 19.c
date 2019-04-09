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
                insertNode(&(*A)->esq,d);
            else
                printf("Duplicação de nó!\n");
        }
    }
}

int flag = 0;

void removeNode(Arvore *A,int t,Arvore *ant)
{
    if(*A != NULL)
    {
         removeNode(&(*A)->esq,t,&(*A));
         removeNode(&(*A)->dir,t,&(*A));
         if((*ant)->dado == t)
         {

            // *ant = NULL;

             free(*ant);
             printf("Nó removido, e seu galho também!\n");

             flag = 1;

             return;
         }

    }
}

void imprime(Arvore A)
{
    if(A != NULL)
    {
        printf("%d ",A->dado);
        imprime(A->esq);
        imprime(A->dir);
    }
}

int main()
{
    setlocale(LC_ALL,"Portuguese");

    Arvore A = NULL;

    int i;
    int x,n;
    int a,b;

    printf("Digite o número de nós que se deseja inserir árvore: ");

    scanf("%d",&n);

    printf("Insira aqui os n elementos:\n");
    for(i = 0;i < n; i++)
    {
        scanf("%d",&x);
        insertNode(&A,x);
    }


    while(1)
    {

        printf("\n\nDigite o elemento que se deseja remover:\n(Podendo apenas estar na árvore e não pode ser um nó folha!)\n");
        printf("-> -1 para sair do programa.\n");



        int t;
        scanf("%d",&t);

        if(t == -1)
            break;
        flag = 0;
        removeNode(&A,t,&A);


        if(!flag)
            printf("O nó desejado não existe na árvore!\n");

        printf("\nÁrvore atual(pre-fíxa):\n");
        imprime(A);

    }
}
