#include<stdio.h>
#include<stdlib.h>

struct no
{
    int coeficiente;
    int expoente;
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

void imprime(lista q)
{
        struct no *aux;
        aux = q.inicio;
        char x;

        while (aux != NULL)
        {

            printf("%d", aux->coeficiente);
            if(aux != q.inicio)
                printf("X");
            else
            {
                printf(" ");
                goto k;
            }
            printf("^%d ",aux->expoente);
            k:
            if(aux->prox != NULL)
                printf("+ ");
            else
                printf("\n");

            aux = aux->prox;
        }
        printf("\n");
}

void lerInserir(lista *q,struct no *novo,int op)
{
    struct no *anterior;
    struct no *atual;


    if(op)
    {
        printf("Digite o coeficiente do polinomio: ");
        scanf("%d",&novo->coeficiente);
        printf("Digite o expoente do polinomio: ");
        scanf("%d",&novo->expoente);
        printf("\n");
    }
    novo->prox = NULL;


    anterior = NULL;
    atual = q->inicio;

    while(atual!=NULL)
    {
        anterior = atual;
        atual = atual->prox;
    }
    if(anterior == NULL)
    {
        novo->prox = q->inicio;
        q->inicio = novo;
    }
    else
    {
        anterior->prox = novo;
        novo->prox = atual;
    }


}

void somaPolinomios(lista Poli1,lista Poli2,lista *soma)
{
    create(soma);

    struct no *aux1 = Poli1.inicio;
    struct no *aux2 = Poli2.inicio;

    while(aux1!= NULL)
    {
        struct no *x;
        x = (struct no*)malloc(sizeof(struct no));

        x->coeficiente = aux1->coeficiente + aux2->coeficiente;
        x->expoente = aux1->expoente;

        lerInserir(soma,x,0);
        aux1 = aux1->prox;
        aux2 = aux2->prox;
    }
}

void Deriva(lista Poli1,lista Poli2,lista *derivada1,lista *derivada2)
{

    struct no *aux;
    aux = Poli1.inicio;

    create(derivada1);

    while(aux != NULL)
    {
        if(aux == Poli1.inicio)
        {
             aux = aux->prox;
             continue;
        }


        struct no *novo;
        novo = (struct no*)malloc(sizeof(struct no));

        novo->coeficiente = aux->coeficiente * aux->expoente;
        novo->expoente = aux->expoente-1;

        lerInserir(derivada1,novo,0);

        aux = aux->prox;
    }
    aux = Poli2.inicio;
    create(derivada2);

    while(aux != NULL)
    {
        if(aux == Poli2.inicio)
        {
             aux = aux->prox;
             continue;
        }


        struct no *novo;
        novo = (struct no*)malloc(sizeof(struct no));

        novo->coeficiente = aux->coeficiente * aux->expoente;
        novo->expoente = aux->expoente-1;

        lerInserir(derivada2,novo,0);

        aux = aux->prox;
    }

}

void multiplicarPolinomio(lista Poli1,lista Poli2,lista *multi)
{
    struct no *aux1;
    struct no *aux2;
    create(multi);

    aux1 = Poli1.inicio;
    aux2 = Poli2.inicio;

    while(aux1!=NULL)
    {





        while(aux2 != NULL)
        {
            struct no *x;
            x = (struct no*)malloc(sizeof(struct no));
            x->expoente = 0;
            x->coeficiente = aux1->coeficiente;
            x->coeficiente *=  aux2->coeficiente;
            x->expoente += aux2->expoente;
            aux2 = aux2->prox;
            lerInserir(multi,x,0);
        }

        aux2 = Poli2.inicio;
        aux1 = aux1->prox;

    }

}

int main()
{
      lista Poli1;
      lista Poli2;
      lista soma;
      lista multi;
      lista derivada1;
      lista derivada2;

      create(&Poli1);
      create(&Poli2);

      int n;
      printf("Digite o valor de n: ");
      scanf("%d",&n);

      int i;

      printf("\n\nPreencha aqui o primeiro polinomio:\n");
      for(i=0;i<=n;i++)
      {
          struct no *novo;
          novo = (struct no*)malloc(sizeof(struct no));
          lerInserir(&Poli1,novo,1);
      }
      printf("\n\n");

      printf("Preencha aqui o segundo polinomio:\n");
      for(i=0;i<=n;i++)
      {
          struct no *novo;
          novo = (struct no*)malloc(sizeof(struct no));
          lerInserir(&Poli2,novo,1);
      }
      printf("\n\n");
      printf("Primeiro polinomio : ");
      imprime(Poli1);


      printf("Segundo polinomio : ");
      imprime(Poli2);
      printf("\n");
      printf("\nSoma dos polinomios: ");
      somaPolinomios(Poli1,Poli2,&soma);
      imprime(soma);
      printf("\n");

      Deriva(Poli1,Poli2,&derivada1,&derivada2);

      printf("\nDerivada do primeiro polinomio: ");
      imprime(derivada1);
      printf("\n");

      printf("\nDerivada do segundo polinomio: ");
      imprime(derivada2);
      printf("\n");

      multiplicarPolinomio(Poli1,Poli2,&multi);
      printf("\nMultiplicao dos polinomios: ");
      imprime(multi);



}
