#include<stdio.h>
#include<stdlib.h>


struct no
{
    struct no *esq;
    struct no *dir;
    char dado;
};

typedef struct no *Arvore;


int ContaNos(Arvore t)
{
    if (t == NULL)
       return 0;
    return ContaNos(t->esq) + ContaNos(t->dir) + 1;
}
void insertNode(Arvore *t, char d)
{
        if (*t == NULL)
        {
            *t = (struct no*) malloc(sizeof(struct no));
            if ( *t != NULL )
            {
                (*t)->esq = NULL;
                (*t)->dir = NULL;
                (*t)->dado = d;
            }
            else
                printf("Memoria insuficiente");
        }
        else
        {
           if (d < (*t)->dado)
              insertNode(&(*t)->esq, d);
           else
           {
               if (d > (*t)->dado)
                 insertNode(&(*t)->dir, d);
               else
                 printf("Duplicação de no");
           }
        }
}

int contaFolhas(Arvore t)
{
    if(t == NULL)
        return 0;
    if(t->dir == NULL && t->esq == NULL)
        return 1;
    return contaFolhas(t->dir)+contaFolhas(t->esq);
}

int contaFilhosDireita(Arvore t)
{
    if(t == NULL)
        return 0;
    if(t->dir != NULL)
        return contaFilhosDireita(t->dir) + contaFilhosDireita(t->esq)+1;
    else
        return contaFilhosDireita(t->dir) + contaFilhosDireita(t->esq);



}

int main()
{
int t;
    printf("Digite o numero de elementos que se deseja inserir na arvore: ");
    scanf("%d",&t);
    int i;
    Arvore A = NULL;
    for(i=0;i<t;i++)
    {
        char x;
        scanf(" %c",&x);
        insertNode(&A,x);
    }
    printf("Quantos nos folhas: %d\n",contaFolhas(A));
    printf("Quantos nos: %d\n",ContaNos(A));
    printf("Quantos filhos a direita : %d\n",contaFilhosDireita(A));
}



