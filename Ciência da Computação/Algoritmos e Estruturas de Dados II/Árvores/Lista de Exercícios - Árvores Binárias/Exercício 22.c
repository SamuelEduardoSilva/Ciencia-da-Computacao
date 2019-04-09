#include<stdio.h>
#include<stdlib.h>
#include<locale.h>
#include<string.h>

struct noFila
{
    int dado;
    struct noFila *prox;
};

typedef struct
{
    struct noFila *inicio;
    struct noFila *fim;
}fila;

struct noArvore
{
    int dado;
    struct noArvore *esq;
    struct noArvore *dir;
};

typedef struct noArvore *Arvore;

void create(fila *q)
{
   q->inicio=NULL;
   q->fim=NULL;
}

void insertNode(Arvore *A,int d)
{
    if(*A == NULL)
    {
        *A = (struct noArvore*)malloc(sizeof(struct noArvore));

        if(*A != NULL)
        {
            (*A)->dado = d;
            (*A)->dir = NULL;
            (*A)->esq = NULL;
        }
        else
            printf("Memória insuficiente!\n");
    }
    else
    {
        if((*A)->dado < d)
            insertNode(&(*A)->dir,d);
        else
        {
            if((*A)->dado > d)
            {
                insertNode(&(*A)->esq,d);
            }
            else
                printf("Duplicação de nó!\n");
        }
    }
}


int isEmpty(fila q)
{
   if (q.inicio == NULL)
      return 1;
   return 0;
}

void insert(fila *q, int d)
{
  struct noFila *aux;
  aux = (struct noFila*) malloc(sizeof(struct noFila));


  aux->dado=d;
  aux->prox=NULL;

  if (q->inicio==NULL)
      q->inicio=aux;
  if (q->fim!=NULL)
      q->fim->prox=aux;

  q->fim=aux;

}

int remover(fila *q,int *d)
{
 struct noFila *aux;

 aux=q->inicio;
 q->inicio=aux->prox;

  *d = aux->dado;
  if (q->inicio==NULL)
     q->fim=NULL;

 free(aux);

}


void geraMatrizAdj(Arvore A,int grade[101][101])
{
     if(A != NULL)
     {
         if(A->esq != NULL)
            grade[A->dado][A->esq->dado] = 1;
         if(A->dir != NULL)
            grade[A->dado][A->dir->dado] = 1;

        geraMatrizAdj(A->esq,grade);
        geraMatrizAdj(A->dir,grade);
     }
}
int niveis[101];
void ImprimeNiveis(Arvore A,int grade[101][101],int raiz)
{
    fila queue;
    create(&queue);

    insert(&queue,raiz);
    niveis[raiz] = 0;
    while(!isEmpty(queue))
    {
        int p;
        remover(&queue,&p);
        int i;
        for(i = 0;i<100;i++)
        {
            if(grade[p][i])
            {
                niveis[i] = niveis[p]+1;
                insert(&queue,i);
            }
        }
    }


}

struct par
{
    int valor;
    int nivel;
};

int main()
{
    Arvore A = NULL;
    int i;
    int x,n;
    int a,b;
    setlocale(LC_ALL,"Portuguese");

    printf("Digite o número de nós que se deseja inserir árvore (valor máx = 100): ");

    scanf("%d",&n);
    int raiz;

    printf("Insira aqui os n elementos (valor máx = 100 / valor min = 1):\n");
    for(i = 0;i < n; i++)
    {

        scanf("%d",&x);

        if(i == 0)
            raiz = x;
        insertNode(&A,x);
    }

    int grade[101][101];


    for(i = 1 ; i <= 100 ; i++)
        memset(grade[i],0,sizeof(grade[i]));

    geraMatrizAdj(A,&(*grade));
    ImprimeNiveis(A,grade,raiz);


    struct par pares[101];
    int p = 0;

    for(i = 1;i<100;i++)
    {
        if(niveis[i] || i==raiz)
        {
            pares[p].nivel = niveis[i];
            pares[p].valor = i;
            p++;
        }
    }
    int j;
    for(i = 0;i<p-1;i++)
    {
        for(j = i+1;j<p;j++)
        {
            if(pares[i].nivel > pares[j].nivel)
            {
                struct par aux;

                aux = pares[i];
                pares[i] = pares[j];
                pares[j] = aux;

            }
        }
    }


    int nivel = 0;
    for(i = 0 ;i<p;i++)
    {
        printf("Valores no nível %d: ",nivel);
        while(pares[i].nivel == nivel)
        {
            printf("%d ",pares[i].valor);
            i++;
        }
        i--;
        nivel++;

        printf("\n");
    }
}
