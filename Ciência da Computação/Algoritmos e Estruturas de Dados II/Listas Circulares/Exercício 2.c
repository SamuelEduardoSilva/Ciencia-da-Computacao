#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<locale.h>

struct Aluno
{
    char nome[100];
    int id;
};

struct no
{
    struct Aluno aluno;
    struct no *prox;
};

typedef struct
{
   struct no *inicio;
   struct no *fim;
}lista;

void create(lista *q)
{
    q->inicio = NULL;
}

void insert(lista *q,char *novo)
{
    struct no *aux;
    aux = (struct no*)malloc(sizeof(struct no));

    memset(aux->aluno.nome,0,sizeof(aux->aluno.nome));
    strcat(aux->aluno.nome,novo);



    if(q->inicio == NULL)
    {
        aux->aluno.id = 1;
        q->inicio = aux;
        q->fim = aux;
        aux->prox = q->inicio;
    }
    else
    {

        aux->aluno.id = size(*q)+1;
        aux->prox = q->inicio;
        q->fim->prox = aux;
        q->fim = aux;
    }

}

int size(lista q)
{
    struct no *aux;
    aux = q.inicio;
    int cont = 0;

    if(aux!=q.fim)
    {
        do
        {
            cont++;
            aux = aux->prox;
        }while(aux != q.inicio);
    }
    else
        cont = 1;

 return cont;
}

void imprime(lista q)
{
    struct no *aux;

    aux = q.inicio;

    if(aux == q.fim)
         printf("%s - %d\n",aux->aluno.nome,aux->aluno.id);
    else
    {
        do
        {

          printf("%s - %d\n",aux->aluno.nome,aux->aluno.id);
          aux= aux->prox;

        }while(aux!=q.inicio);
    }


}



char* removeAlternado(lista *l,int p)
{
      int remove = 1;

      struct no *atual,*anterior;


         anterior = l->fim;
         atual = l->inicio;

        while(p != atual->aluno.id)
        {
             anterior = atual;
             atual = atual->prox;
         }

      while(size(*l) > 1)
      {

          struct no *aux;
          if(!remove)
          {
               anterior = atual;
               atual = atual->prox;
               remove = 1;
          }
          else
          {
              imprime(*l);
              printf("\nTamanho da roda = %d\n",size(*l));
              printf("Removido = %s\n\n",atual->aluno.nome);
              remove = 0;
              aux = atual;
              if(aux == l->inicio)
              {
                  l->inicio = l->inicio->prox;
                  atual = l->inicio;
                  anterior->prox = l->inicio;
                  free(aux);
                  continue;
              }
              atual = atual->prox;
              anterior->prox = atual;
              free(aux);
          }
      }
      return l->inicio->aluno.nome;
}

int main()
{
    lista a;
    create(&a);

    setlocale(LC_ALL,"Portuguese");

    insert(&a,"Samuel");
    insert(&a,"Pedro");
    insert(&a,"Luiz");
    insert(&a,"Juca");
    insert(&a,"Tadeu");
    insert(&a,"Nayara");
    insert(&a,"Joice");
    insert(&a,"Maria");
    insert(&a,"Leticia");
    insert(&a,"Paola");
    printf("Roda:\n");
    imprime(a);
    printf("\n");
    printf("Digite a posição da roda em que se deseja começar a remover: ");
    int p;
    scanf("%d",&p);

    printf("Ultimo da roda = %s\n",removeAlternado(&a,p));
}
