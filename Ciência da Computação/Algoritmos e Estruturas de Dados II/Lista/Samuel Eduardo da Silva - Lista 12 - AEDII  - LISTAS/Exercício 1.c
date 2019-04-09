#include<stdio.h>
#include<stdlib.h>
#include<locale.h>


struct no
{
    int dado;
    struct no *prox;
};


typedef struct
{
    struct no *inicio;
}lista;


void create(lista *q)
{
    q->inicio = NULL;

}

int isEmpty(lista q)
{
    if(q.inicio == NULL)
        return 1;
    return 0;
}

int insert(lista *q, int d,int op,int pos)
{
        struct no *aux, *atual, *anterior;
        aux = (struct no *) malloc(sizeof(struct no));
        if (aux!=NULL)
        {
                aux->dado=d;
                aux->prox=NULL;
                if(op == 1)
                {
                        aux->prox = q->inicio;
                        q->inicio = aux;
                }
                else if(op == 2)
                {
                       anterior = NULL;
                       atual = q->inicio;
                       int cont = 1;

                       while(atual!=NULL && cont<pos)
                       {
                           anterior = atual;
                           atual = atual->prox;
                           cont++;
                       }
                       if (anterior == NULL)
                       {
                            aux->prox = q->inicio;
                            q->inicio = aux;
                       }
                       else
                       {
                            anterior->prox=aux;
                            aux->prox = atual;
                       }

                }
                else
                {
                     anterior = NULL; atual = q->inicio;
                     while (atual != NULL)
                     {
                        anterior = atual;
                        atual = atual->prox;
                     }
                     if (anterior == NULL)
                     {
                            aux->prox = q->inicio;
                            q->inicio = aux;
                     }
                     else
                     {
                            anterior->prox=aux;
                            aux->prox = atual;
                     }
                }
        }
}
void imprime(lista q)
{
        struct no *aux;
        aux = q.inicio;
        if (!isEmpty(q))
        {
            while (aux != NULL)
            {
                printf("%d ", aux->dado);
                aux = aux->prox;
            }
        }
}

int remover(lista *q, int op,int pos)
{
    struct no *aux, *atual, *anterior;
    if(op == 4)
    {
        aux = q->inicio;
        q->inicio = (q->inicio)->prox;
        free(aux);
    }
    else if(op == 5)
    {
        anterior = q->inicio;
        atual = (q->inicio)->prox;
        int cont = 0;
        while (atual != NULL && cont<pos)
        {
            anterior = atual;
            atual = atual->prox;
            cont++;
        }
        if (atual != NULL)
        {
            aux = atual;
            anterior->prox = atual->prox;
            free(aux);
        }
    }
    else if(op == 6)
    {
        anterior = q->inicio;
        atual = (q->inicio)->prox;
        while (atual->prox != NULL)
        {
            anterior = atual;
            atual = atual->prox;
        }
        if (atual != NULL)
        {
            aux = atual;
            anterior->prox = atual->prox;
            free(aux);
        }
    }
}

int size(lista q)
{
    struct no *aux;
    aux = q.inicio;
    int cont = 0;

    if(aux == NULL)
        return 0;
    while(aux!=NULL)
    {
        cont++;
        aux = aux->prox;
    }
    return cont;
}

int busca(lista q,int procurado)
{
    struct no *aux;
    aux = q.inicio;
    int cont = 0;
    if(procurado == aux->dado)
    {
        printf("Elemento encontrado  na posição 1!\n");
        return 1;
    }
    else
    {
        while(aux!=NULL)
        {
            cont++;
            if(procurado == aux->dado)
            {
                printf("Elemento encontrado na posição %d!\n",cont);

                return 1;
            }
            aux = aux->prox;
        }
    }
    return 0;
}

int main()
{
    setlocale(LC_ALL,"Portuguese");

    printf("---- Menu ---\n");
    printf("1 - Insere no início.\n");
    printf("2 - Insere no meio(passando o valor e a posição a ser inserido).\n");
    printf("3 - Insere no fim.\n");
    printf("4 - Retira do início.\n");
    printf("5 - Retira do meio(passando o valor e a posição a ser removido).\n");
    printf("6 - Retira do fim.\n");
    printf("7 - Imprime.\n");
    printf("8 - Busca.\n");
    printf("9 - Sai do programa.\n");

    lista q;
    int op;
    create(&q);


    printf("Digite a opção desejada : ");
    scanf("%d",&op);

    while(op != 9)
    {
        int dado;
        if(op == 1)
        {
            printf("Digite o valor a ser inserido no início: ");
            scanf("%d",&dado);
            insert(&q,dado,1,0);
        }
        else if(op == 2)
        {
            printf("Digite o valor a ser inserido no meio: ");
            scanf("%d",&dado);
            printf("Tamanho atual da lista: %d\n",size(q));
            int pos;
            printf("Digite a posição em que se quer colocar: ");
            scanf("%d",&pos);
            insert(&q,dado,2,pos);
        }
        else if(op == 3)
        {
            printf("Digite o valor a ser inserido no fim: ");
            scanf("%d",&dado);
            insert(&q,dado,3,0);
        }
        else if(op == 4)
        {
            remover(&q,4,0);
            printf("Elemento do inicio removido!\n");

        }
        else if(op == 5)
        {
            int pos;
            printf("Tamanho atual a lista: %d\n",size(q));
            printf("Digite a posição do elemento a ser removido: ");
            scanf("%d",&pos);
            remover(&q,5,pos);

        }
        else if(op == 6)
        {
            remover(&q,6,0);
            printf("Elemento do fim removido!\n");
        }
        else if(op == 7)
        {
            imprime(q);

        }
        else if(op == 8)
        {
            int search;
            printf("Digite o elemento a ser buscado: ");
            scanf("%d",&search);
            if(!busca(q,search))
                printf("Elemento não encontrado!\n");

        }
        printf("\n");
        printf("Digite a opção desejada : ");
        scanf("%d",&op);

    }
}
