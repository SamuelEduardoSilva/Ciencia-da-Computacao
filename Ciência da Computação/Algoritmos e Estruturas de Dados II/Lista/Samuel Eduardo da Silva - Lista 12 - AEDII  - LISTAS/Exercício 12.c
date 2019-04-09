#include<stdio.h>
#include<stdlib.h>
#include<locale.h>
#include<string.h>
struct no
{
    struct no *ant;
    struct no *prox;
    int dado;
};

typedef struct
{

    struct no *inicio;
    struct no *fim;
    struct no *atual;


}lista;

void create(lista *q)
{
    q->inicio = NULL;
    q->fim = NULL;

    q->atual = NULL;


}

void inserir(lista *q,int d)
{
    struct no *aux;
    struct no *anterior;
    struct no *atual;

    aux = (struct no*)malloc(sizeof(struct no));
    aux -> dado = d;

    if(q->inicio == NULL)
    {
        aux -> ant =NULL;
        aux -> prox = NULL;
        q->inicio = aux;
        q->fim = aux;
        return;
    }
    aux->prox = NULL;
    aux->ant = q->fim;
    q->fim->prox = aux;
    q->fim = aux;
}

int main()
{
    setlocale(LC_ALL,"Portuguese");

    lista Elevador;

    create(&Elevador);

    inserir(&Elevador,1);
    inserir(&Elevador,2);
    inserir(&Elevador,3);
    inserir(&Elevador,4);
    inserir(&Elevador,5);
    inserir(&Elevador,6);
    inserir(&Elevador,7);
    inserir(&Elevador,8);
    inserir(&Elevador,9);
    inserir(&Elevador,10);



   char S1[] = {"Pode!"};
   char S2[] = {"Não Pode!"};
   int desejado;

    Elevador.atual = Elevador.inicio;

    while(1)
    {
        char Sit1[30];
        char Sit2[30];

        memset(Sit1,0,sizeof(Sit1));
        memset(Sit2,0,sizeof(Sit2));
        printf("---------Sistema de Elevador---------\n\n");
        printf("--> Andar Atual : %d\n",Elevador.atual->dado);
        if(Elevador.atual->prox != NULL)
            strcpy(Sit1,S1);
        else
            strcpy(Sit1,S2);


        if(Elevador.atual->ant !=NULL)
            strcpy(Sit2,S1);
        else
            strcpy(Sit2,S2);
        printf("^                  |\n");
        printf("|                  |\n");
        printf("|                  v\n");
        printf("Cima : %s   Baixo : %s\n\n",Sit1,Sit2);

        printf("Digite o andar desejado: ");
        scanf("%d",&desejado);



        if(Elevador.atual->dado < desejado)
        {
            while(Elevador.atual->dado != desejado)
            {
                Elevador.atual = Elevador.atual->prox;
            }
        }
        else
        {
            while(Elevador.atual->dado != desejado)
            {
                Elevador.atual = Elevador.atual->ant;
            }
        }
        system("cls");
    }
}
