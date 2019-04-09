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

void doit(Arvore t,char x)
{
    if(t!=NULL)
    {
       if(t->dado == x)
       {
           char d=';';
           char e=';';
           if(t->dir != NULL)
              d = t->dir->dado;
           if(t->esq != NULL)
              e = t->esq->dado;

           if(d == e && d == ';')
             printf("O elemento não tem filhos!\n");
           else
           {
               printf("Seu(s) filho(s) é/são: ");
               if(d != ';')
                   printf("%c ",d);
               if(e != ';')
                   printf("%c",e);
               printf("\n");
           }

       }
       doit(t->dir,x);
       doit(t->esq,x);
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
    printf("Digite o elemento: ");
    scanf(" %c",&x);

    doit(A,x);
}
