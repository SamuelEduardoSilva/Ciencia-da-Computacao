#include<stdio.h>
#include<stdlib.h>
#include<locale.h>

/// let the world call me a fool...
/// Samuel

struct no
{
    int chave;
    char cor;
    struct no *dir;
    struct no *esq;
    struct no *pai;
};

struct no *NIL;

typedef struct no *rb;

void rotation_left(rb *T,struct no *x)
{
    struct no *y = x->dir;
    x->dir = y->esq;

    if(y->esq != NIL)
        y->esq->pai = x;

    y->pai = x->pai;
    if (x->pai == NIL)
        (*T) = y;
    else if(x == x->pai->esq)
        x->pai->esq = y;
    else
        x->pai->dir = y;
    y->esq = x;
    x->pai = y;
}

void rotation_right(rb *T,struct no *x)
{

    struct no *y = x->esq;
    x->esq = y->dir;


    if(y->dir != NIL)
        y->dir->pai = x;

    y->pai = x->pai;

    if(x->pai == NIL)
    {
        (*T) = y;
    }
    else if(x == x->pai->esq)
    {
        x->pai->esq = y;
    }
    else
        x->pai->dir = y;

    y->dir = x;
    x->pai = y;
}



void rb_insert_fixup(rb *T,struct no *z)
{
    struct no *y;


    if(z->pai == NIL)
        goto fim;
    while(z->pai->cor == 'V')
    {

        if(z->pai == z->pai->pai->esq)
        {

            y = z->pai->pai->dir;
            if(y->cor == 'V')
            {
                z->pai->cor = 'P';
                y->cor = 'P';
                z->pai->pai->cor = 'V';
                z = z->pai->pai;

            }
            else
            {
                if(z == z->pai->dir)
                {
                    z = z->pai;
                    rotation_left(&(*T),z);
                }

                 z->pai->cor = 'P';
                 z->pai->pai->cor = 'V';
                 rotation_right(&(*T),z->pai->pai);
            }
        }
        else if (z->pai == z->pai->pai->dir)
        {

             y = z->pai->pai->esq;
            if(y->cor == 'V')
            {
                z->pai->cor = 'P';
                y->cor = 'P';
                z->pai->pai->cor = 'V';
                z = z->pai->pai;
            }
            else
            {
                if(z == z->pai->esq)
                {
                    z = z->pai;
                    rotation_right(&(*T),z);
                }
                z->pai->cor = 'P';
                z->pai->pai->cor = 'V';
                rotation_left(&(*T),z->pai->pai);
            }
        }
    }

    fim:
    (*T)->cor = 'P';
}


void insere_rb(rb *T,int valor)
{
    struct no *y = NIL;
    struct no *x = *T;

    struct no *z = (struct no*)malloc(sizeof(struct no));
    z->chave = valor;
    z->dir = NIL;
    z->esq = NIL;

    if(*T == NULL)
    {
        z->pai = NIL;
        z->cor = 'P';
        *T = z;
        return;
    }
    while(x != NIL)
    {
        y = x;
        if(z -> chave < x->chave)
            x = x->esq;
        else
            x = x->dir;
    }

    z->pai = y;

    if(y == NIL)
        *T = z;
    else if(z->chave < y ->chave)
        y->esq = z;

    else
        y->dir = z;
     z->cor = 'V';
     rb_insert_fixup(&(*T),z);
}

void showPrefixe(rb t)
{
    if(t!=NIL && t != NULL)
    {
        printf("%d ",t->chave);
        showPrefixe(t->esq);
        showPrefixe(t->dir);
    }

}

void showInfixe(rb t)
{
    if(t!=NIL && t != NULL)
    {

        showInfixe(t->esq);
        printf("%d\n",t->chave);
        showInfixe(t->dir);
    }

}

void showPosfixe(rb t)
{
    if(t!=NIL && t!=NULL)
    {

        showPosfixe(t->esq);
        showPosfixe(t->dir);
        printf("%d\n",t->chave);
    }

}

int contaNos(rb t)
{
    if(t == NIL || t == NULL)
        return 0;
    else
        return 1 + contaNos(t->dir) + contaNos(t->esq);
}

int contaFolhas(rb t)
{

    if(t == NIL && t == NULL)
        return 0;
    if (t->esq == NULL && t->dir == NULL)
        return 1;
    return contaFolhas(t->esq) + contaFolhas(t->dir);
}

int max(int a,int b)
{
    if(a > b)
        return a;
    else
        return b;
}

int calculaAltura(rb t)
{
    if(t == NIL || t == NULL)
        return 0;
    return max(calculaAltura(t->esq),calculaAltura(t->dir))+1;
}

int flag = 0;
void procurar(rb t,int s)
{
    if(t != NIL && t != NULL)
    {
        if(t->chave == s)
        {
            flag  = 1;
            return;
        }
        procurar(t->esq,s);
        procurar(t->dir,s);
    }
}

int main()
{
   rb rubro_negra  = NULL;

   setlocale(LC_ALL,"Portuguese");

   NIL = (struct no*)malloc(sizeof(struct no));

   NIL->cor = 'P';
   NIL->dir = NIL;
   NIL->esq = NIL;

   int p;


    while(p != 10)
    {
        printf("* Árvore Rubro Negra *\n");
        printf("-- Menu --\n");
        printf("1 - Inserir valor.\n");
        printf("2 - Mostrar Pré-Fixa.\n");
        printf("3 - Mostrar In-Fixa.\n");
        printf("4 - Mostrar Pós-Fixa.\n");
        printf("5 - Resetar árvore.\n");
        printf("6 - Contar Nós.\n");
        printf("7 - Contar Nós Folhas.\n");
        printf("8 - Mostrar altura da árvore.\n");
        printf("9 - Procurar um nó.\n");
        printf("10 - Sair.\n");
        printf("\nDigite a opção desejada: ");
        scanf("%d",&p);
        if(p == 1)
        {
            int n;
            printf("\nDigite um valor a ser inserido na árvore: ");
            scanf("%d",&n);
            insere_rb(&rubro_negra,n);
        }
        else if(p == 2)
        {
            printf("\nÁrvore em ordem Pré-Fixa:\n");
            showPrefixe(rubro_negra);
        }
        else if(p == 3)
        {
            printf("\nÁrvore em ordem In-Fixa:\n");
            showInfixe(rubro_negra);
        }
        else if(p == 4)
        {
            printf("\nÁrvore em ordem Pós-Fixa:\n");
            showPosfixe(rubro_negra);
        }
        else if(p == 5)
        {
            free(rubro_negra);
            rubro_negra = NULL;
            printf("\nÁrvore resetada!\n");
        }
        else if(p == 6)
        {
            printf("\nA árvore tem %d nós!\n",contaNos(rubro_negra));
        }
        else if(p == 7)
        {
            printf("\nA árvore tem %d nós folhas!\n",contaFolhas(rubro_negra));
        }
        else if(p == 8)
        {
            if(rubro_negra == NULL)
                printf("\nA árvore tem altura 0!\n");
            else
                printf("\nA árvore tem altura %d!\n",calculaAltura(rubro_negra));
        }
        else if(p == 9)
        {
            flag = 0;
            printf("\nDigite o nó a ser procurado: ");
            int s;

            scanf("%d",&s);

            procurar(rubro_negra,s);

            (flag) ? printf("Nó encontrado!\n") : printf("Nó não encontrado!\n");
        }
        else if(p == 10)
        {
            goto sair;
        }
        printf("\nContinuar ? : 1 (Sim) | 2 (Não)\n");
        int x;
        scanf("%d",&x);
        if(x == 2)
        {
            sair:
            printf("Saindo...\n");
            break;
        }
        system("cls");
    }
}
