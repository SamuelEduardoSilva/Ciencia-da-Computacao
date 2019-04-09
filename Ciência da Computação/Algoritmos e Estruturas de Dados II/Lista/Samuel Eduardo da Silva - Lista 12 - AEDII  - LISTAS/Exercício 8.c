#include<stdio.h>
#include<stdlib.h>
#include<locale.h>
#include<string.h>
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

void insert(lista *q , int d)
{
    struct no *aux;
    struct no *atual;
    struct no *anterior;
    aux = (struct no*)malloc(sizeof(struct no));

    aux->dado = d;
    aux->prox =NULL;

    anterior = NULL;
    atual = q->inicio;

    while(atual!=NULL)
    {
        anterior = atual;
        atual = anterior->prox;
    }

    if(anterior == NULL)
    {
        aux->prox = q->inicio;
        q->inicio = aux;
    }
    else
    {
        anterior->prox = aux;
        aux->prox = atual;
    }
}
void imprime(lista q)
{
        struct no *aux;
        aux = q.inicio;

        while (aux != NULL)
        {
            printf("%d ", aux->dado);
            aux = aux->prox;
        }
        printf("\n");
}

void ConjuntoUniao(lista *Uniao,lista A,lista B)
{
    struct no *aux;
    create(Uniao);
    aux = A.inicio;

    while(aux!=NULL)
    {
        insert(Uniao,aux->dado);
        aux = aux->prox;
    }
    aux = B.inicio;

    while(aux!=NULL)
    {
        insert(Uniao,aux->dado);
        aux = aux->prox;
    }
}

int tamanho(lista q)
{
    int cont = 0;
    struct no *aux;

    aux = q.inicio;

    while(aux != NULL)
    {
        cont++;
        aux = aux->prox;
    }
    return cont;
}

void ConjuntoIntersecao(lista *Intersecao,lista A,lista B,int MarcaA[],int MarcaB[])
{
    struct no *aux1;
    struct no *aux2;
    create(Intersecao);
    aux1 = A.inicio;
    aux2 = B.inicio;

    int contB = 0;
    int contA = 0;



    while(aux1 != NULL)
    {
        int x = aux1->dado;


        while(aux2 != NULL)
        {

            int y = aux2->dado;
            if(x == y && !MarcaB[contB])
            {

                MarcaB[contB] = 1;
                MarcaA[contA] = 1;
                insert(Intersecao,x);
                break;
            }
            contB++;
            aux2 = aux2->prox;
        }
        contA++;
        contB = 0;
        aux2 = B.inicio;
        aux1 = aux1->prox;
    }
}

void ConjuntoPertence(lista A,int x)
{
    struct no *aux;

    aux = A.inicio;

    while(aux!=NULL)
    {
        if(aux->dado == x)
        {
            printf("Elemento pertence ao conjunto A!\n");
            return;
        }

        aux = aux -> prox;
    }
    printf("Elemento não pertence ao conjunto A!\n");
}

void ConjuntoDiferenca(lista *Diferenca,lista A,lista B,int MarcaA[],int MarcaB[])
{
    create(Diferenca);

    struct no *aux1 = A.inicio;
    struct no *aux2 = B.inicio;
    int cont = 0;
    while(aux1!=NULL)
    {
        if(!MarcaA[cont])
          insert(Diferenca,aux1->dado);
        aux1 = aux1->prox;
        cont++;
    }
    cont = 0;
    while(aux2 != NULL)
    {
        if(!MarcaB[cont])
            insert(Diferenca,aux2->dado);
        cont++;
        aux2 = aux2->prox;
    }

}
int main()
{
    setlocale(LC_ALL,"Portuguese");
    lista A,B;
    lista Uniao;
    lista Intersecao;
    lista Diferenca;

    create(&A);
    create(&B);

    insert(&A,3);
    insert(&A,2);
    insert(&A,3);
    insert(&A,4);
    insert(&A,5);
    insert(&A,6);
    insert(&A,7);

    insert(&B,1);
    insert(&B,4);
    insert(&B,9);
    insert(&B,10);
    insert(&B,11);
    insert(&B,1);
    insert(&B,3);

    printf("Conjunto A:\n");
    imprime(A);
    printf("Conjunto B:\n");
    imprime(B);


    int MarcaB[tamanho(B)+2];
    memset(MarcaB,0,sizeof(MarcaB));
    int MarcaA[tamanho(A)+2];
    memset(MarcaA,0,sizeof(MarcaA));

    ConjuntoUniao(&Uniao,A,B);
    printf("\nConjunto União de A e B:\n");
    imprime(Uniao);


    ConjuntoIntersecao(&Intersecao,A,B,MarcaA,MarcaB);
    printf("\nConjunto Intersecção de A e B:\n");
    imprime(Intersecao);

    int x;
    printf("\nDigite um elemento para ver se ele pertence ao conjunto A: ");
    scanf("%d",&x);
    ConjuntoPertence(A,x);

    printf("\nConjunto Diferença de A e B:\n");
    ConjuntoDiferenca(&Diferenca,A,B,MarcaA,MarcaB);
    imprime(Diferenca);

}
