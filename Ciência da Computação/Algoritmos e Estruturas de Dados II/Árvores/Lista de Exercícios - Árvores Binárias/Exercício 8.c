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
int checkIgual(Arvore a,Arvore b){
    if(a==NULL && b==NULL)
            return 1;
    if(a==NULL || b==NULL)
            return 0;
    return ((a->dado == b->dado) && checkIgual(a->esq,b->esq) && checkIgual(a->dir,b->dir));
}
int main()
{
    int t;
    Arvore A = NULL;
    Arvore B = NULL;
    printf("Digite o numero de elementos que se deseja inserir na primeira arvore: ");
    scanf("%d",&t);
    int i;

    setlocale(LC_ALL,"Portuguese");

    for(i=0;i<t;i++)
    {
        char x;
        scanf(" %c",&x);
        insertNode(&A,x);
    }

    printf("Digite o numero de elementos que se deseja inserir na segunda arvore: ");
    scanf("%d",&t);
    for(i=0;i<t;i++)
    {
        char x;
        scanf(" %c",&x);
        insertNode(&B,x);
    }

    int ans = checkIgual(A,B);

    if(!ans)
        printf("As árvores são diferentes!\n");
    else
        printf("As árvores são iguais!\n");

}

