#include<stdio.h>
#include<stdlib.h>
#include<locale.h>

struct no
{
    char dado;
    struct no *dir;
    struct no *esq;
};


typedef struct no *Arvore;


void insertNode(Arvore *t,char p)
{
    if(*t == NULL)
    {
        *t = (struct no*)malloc(sizeof(struct no));
        if(*t != NULL)
        {
            (*t)->dir = NULL;
            (*t)->esq = NULL;
            (*t)->dado = p;
        }
        else
            printf("Memória insuficiente!\n");
    }
    else
    {
        if((*t)->dado > p)
            insertNode(&(*t)->esq,p);
        else
        {
            if((*t)->dado < p)
                insertNode(&(*t)->dir,p);
            else
                printf("Duplicação de nó!\n");
        }
    }
}
int flag = 0;
void Pesquisa(Arvore t,char d)
{
    if(t!=NULL)
    {
        if(t->dado == d)
        {
            printf("Elemento encontrado no endereço de memória: %p",&t);
            flag = 1;
        }


        Pesquisa(t->dir,d);
        Pesquisa(t->esq,d);
    }
}

int main()
{
    int t;
    Arvore A = NULL;
    printf("Digite o numero de elementos que se deseja inserir na arvore: ");
    scanf("%d",&t);
    int i;

    setlocale(LC_ALL,"Portuguese");

    for(i=0;i<t;i++)
    {
        char x;
        scanf(" %c",&x);
        insertNode(&A,x);
    }
    char x;
    printf("Digite o elemento que se deseja procurar na arvore: ");
    scanf(" %c",&x);
    Pesquisa(A,x);
    if(!flag)
        printf("Elemento não encontrado!\n");
}
