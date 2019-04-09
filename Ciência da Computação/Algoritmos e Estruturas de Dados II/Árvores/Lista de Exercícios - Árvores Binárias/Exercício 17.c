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

int Altura (Arvore A)
{
   if (A == NULL)
      return -1;
   else
   {
      int AlturaEsquerda = Altura(A->esq);
      int AlturaDireita = Altura(A->dir);


      if (AlturaEsquerda < AlturaDireita)
         return AlturaDireita + 1;
      else
         return AlturaEsquerda + 1;
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

    int ans = Altura(A);

    printf("A altura dessa árvore é: %d\n",ans);
}
