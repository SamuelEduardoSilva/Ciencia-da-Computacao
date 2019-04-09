#include<stdio.h>
#include<stdlib.h>
#include<locale.h>

typedef struct no* avl;

struct no
{
    int chave;
    int alt;
    struct no *esq;
    struct no *dir;
};



int calculaAltura(struct no *t)
{
	if(t == NULL)
		return -1;
	return t->alt;
}
void rotation_left(avl *t)
{
	struct no *y;
	y = (*t)->esq;
	(*t)->esq = y -> dir;
	y->dir = *t;
	(*t)->alt = max(calculaAltura((*t)->esq),calculaAltura((*t)->dir)) + 1;

	y->alt = max(calculaAltura(y->esq),(*t)->alt)+1;

	*t = y;
}

void rotation_right(avl *t)
{
	struct no *y;
	y = (*t)->dir;
	(*t)->dir = y->esq;
	y->esq = (*t);

    (*t)->alt = max(calculaAltura((*t)->esq),calculaAltura((*t)->dir)) + 1;

	y->alt = max(calculaAltura(y->dir),(*t)->alt)+1;

	*t = y;
}

void rotation_left_right(avl *t)
{
	rotation_right(&(*t)->esq);
	rotation_left(t);
}

void rotation_right_left(avl *t)
{
	rotation_left(&(*t)->dir);
	rotation_right(t);
}

/// remoção
/// remover um nó da sub-árvore a direita,
/// equivale a inserir um nó na sub-árvore,
/// da esquerda. e vice-versa

///se o nó a ser removido tiver 2 filhos
///substituir pelo nó mais a esquerda da sub-árvore,
/// da direita

struct no* procuraMenor(struct no *atual)
{
    struct no *n1 = atual;
    struct no *n2 = atual->esq;
    while(n2 != NULL)
    {
        n1 = n2;
        n2 = n2->esq;
    }
    return n1;
}

int remove_avl(avl *t, int valor)
{
    if(*t == NULL)
    {
        printf("valor não existe!\n");
        return 0;
    }
    int res;
    if(valor < (*t)->chave)
    {
        if((res = remove_avl(&(*t)->esq,valor)) == 1)
        {
            if(calculaFB(*t)>=2)
            {
                if(calculaAltura((*t)->dir->esq) <= calculaAltura((*t)->dir->dir))
                    rotation_right(t);
                else
                    rotation_right_left(t);
            }
        }
    }
    if((*t)->chave < valor)
    {
        if((res == remove_avl(&(*t)->dir,valor)) == 1)
        {
            if(calculaFB(*t) >= 2)
            {
                if(calculaAltura((*t)->esq->dir)<= calculaAltura((*t)->esq->esq))
                    rotation_left(t);
                else
                    rotation_left_right(t);
            }
        }
    }
    if((*t)->chave == valor)
    {
        if(((*t)->esq == NULL || (*t)->dir == NULL))
        {
           struct no *removido = *t;
           if((*t)->esq != NULL)
                (*t) = (*t)->esq;
           else
                (*t) = (*t)->dir;
           free(removido);
        }
        else
        {
            struct no *temp = procuraMenor((*t)->dir);
            (*t)->chave = temp->chave;
            remove_avl(&(*t)->dir,(*t)->chave);
            if(calculaAltura(*t) >= 2)
            {
                if(calculaAltura((*t)->esq->dir) <= calculaAltura((*t)->esq->esq))
                    rotation_left(t);
                else
                    rotation_left_right(t);
            }
        }
        return 1;

    }
    return res;
}




int calculaFB(struct no *t)
{
	return abs(calculaAltura(t->esq) - calculaAltura(t->dir));
}

int max(int x, int y)
{
	if(x > y)
		return x;
	return y;
}



int insere_avl(avl *t,int valor)
{
    int res;

    if(*t == NULL)
    {
        struct no *novo = (struct no*)malloc(sizeof(struct no));

        if(novo == NULL)
        {
        	printf("Memoria insuficiente!\n");
        	return 0;
        }
        novo->chave = valor;
        novo->alt = 0;
        novo->esq = novo->dir = NULL;
         *t = novo;
        return 1;
    }
    struct no *atual = *t;
    if(valor < atual->chave)
    {
    	if((res = insere_avl(&(atual->esq),valor)) == 1)
        {
             if(calculaFB(atual) >=2)
             {
             	if(valor < (atual)->esq->chave)
             		rotation_left(t);
             	else
             		rotation_left_right(t);

             }
        }
    }
    else
    {
    	if(valor > atual->chave)
    	{
    		if((res = insere_avl(&(atual->dir),valor)) == 1)
    		{
    			if(calculaFB(atual)>=2)
    			{
    				if((atual)->dir->chave < valor)
    					rotation_right(t);
    				else
    					rotation_right_left(t);
    			}
    		}
    	}
    	else
    	{
    		printf("No duplicado!\n");
    		return 0;
    	}
    }
    atual->alt = max(calculaAltura(atual->esq),calculaAltura(atual->dir)) + 1;

    return res;

}

void showPrefixe(avl t)
{
    if(t!=NULL)
    {
        printf("%d ",t->chave);
        showPrefixe(t->esq);
        showPrefixe(t->dir);
    }

}

void showInfixe(avl t)
{
    if(t!=NULL)
    {

        showInfixe(t->esq);
        printf("%d\n",t->chave);
        showInfixe(t->dir);
    }

}

void showPosfixe(avl t)
{
    if(t!=NULL)
    {

        showPosfixe(t->esq);
        showPosfixe(t->dir);
        printf("%d\n",t->chave);
    }

}

int flag;

void procurar(avl t,int s)
{
    if(t != NULL)
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


int contaNos(avl t)
{
    if(t == NULL)
        return 0;
    else
        return 1 + contaNos(t->dir) + contaNos(t->esq);
}

int contaFolhas(avl t)
{

    if(t == NULL)
        return 0;
    if (t->esq == NULL && t->dir == NULL)
        return 1;
    return contaFolhas(t->esq) + contaFolhas(t->dir);
}

int main()
{
    avl AVL = NULL;
    setlocale(LC_ALL,"Portuguese");

    int p;


    while(p != 11)
    {
        printf("* Árvore AVL *\n");
        printf("-- Menu --\n");
        printf("1 - Inserir valor.\n");
        printf("2 - Remover valor.\n");
        printf("3 - Mostrar Pré-Fixa.\n");
        printf("4 - Mostrar In-Fixa.\n");
        printf("5 - Mostrar Pós-Fixa.\n");
        printf("6 - Resetar árvore.\n");
        printf("7 - Contar Nós.\n");
        printf("8 - Contar Nós Folhas.\n");
        printf("9 - Mostrar altura da árvore.\n");
        printf("10 - Procurar um nó.\n");
        printf("11 - Sair.\n");
        printf("\nDigite a opção desejada: ");
        scanf("%d",&p);
        if(p == 1)
        {
            int n;
            printf("\nDigite um valor a ser inserido na árvore: ");
            scanf("%d",&n);
            insere_avl(&AVL,n);
        }
        else if(p == 2)
        {
            int n;
            printf("\nDigite o valor a ser removido da árvore: ");
            scanf("%d",&n);
            remove_avl(&AVL,n);
        }
        else if(p == 3)
        {
            printf("\nÁrvore em ordem Pré-Fixa:\n");
            showPrefixe(AVL);
        }
        else if(p == 4)
        {
            printf("\nÁrvore em ordem In-Fixa:\n");
            showInfixe(AVL);
        }
        else if(p == 5)
        {
            printf("\nÁrvore em ordem Pós-Fixa:\n");
            showPosfixe(AVL);
        }
        else if(p == 6)
        {
            free(AVL);
            AVL = NULL;
            printf("\nÁrvore resetada!\n");
        }
        else if(p == 7)
        {
            printf("\nA árvore tem %d nós!\n",contaNos(AVL));
        }
        else if(p == 8)
        {
            printf("\nA árvore tem %d nós folhas!\n",contaFolhas(AVL));
        }
        else if(p == 9)
        {
            printf("\nA árvore tem altura %d!\n",calculaAltura(AVL)+1);
        }
        else if(p == 10)
        {
            flag = 0;
            printf("\nDigite o nó a ser procurado: ");
            int s;

            scanf("%d",&s);

            procurar(AVL,s);

            (flag) ? printf("Nó encontrado!\n") : printf("Nó não encontrado!\n");
        }
        else if(p == 11)
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
