#include<stdio.h>
#include<string.h>
#define N 8



typedef struct
{
    char nome[50];
    double n1;
    double n2;
    char aprovados[50];
}alunos;

void InsertionSort(alunos vet[], int tam)
{
  int i, j;
  alunos eleito;

  for (i = 1; i < tam; i++)
  {
    eleito = vet[i];
    j = i - 1;
    while ((j>=0) && (strcmp(eleito.nome , vet[j].nome)<0))
    {
        vet[j+1] = vet[j];
        j--;
    }
    vet[j+1] = eleito;
  }
}
void InsertionSort2(alunos vet[], int tam)
{
  int i, j;
  alunos eleito;

  for (i = 1; i < tam; i++)
  {
    eleito = vet[i];
    j = i - 1;
    while ((j>=0) && (strcmp(eleito.aprovados , vet[j].aprovados)<0))
    {
        vet[j+1] = vet[j];
        j--;
    }
    vet[j+1] = eleito;
  }
}


void SelectionSort(alunos vet[], int tam)
{
  int i, j, min;
  alunos aux;
  for (i = 0; i < (tam-1); i++)
  {
    min = i;
    for (j = (i+1); j < tam; j++)
    {
        if(vet[j].n1 < vet[min].n1)
            min = j;
    }
    if (i != min)
    {
      aux = vet[i];
      vet[i] = vet[min];
      vet[min] = aux;
    }
  }
}

int main()
{
    alunos x[N];
    int i;
    printf("Cadastre aqui os alunos:\n");
    for(i=0;i<N;i++)
    {
        printf("\nAluno %d:\n",i+1);
        printf("Digite o nome: ");
        scanf("%50[^\n]",x[i].nome);
        getchar();
        printf("Nota 1 = ");
        scanf("%lf",&x[i].n1);
        getchar();
        printf("Nota 2 = ");
        scanf("%lf",&x[i].n2);
        getchar();
    }
    InsertionSort(x,N);
    printf("\nAlunos ordenados pelo nome:\n");
    for(i=0;i<N;i++)
    {
        printf("Aluno %d:\n",i+1);
        printf("Nome = %s\n",x[i].nome);
        printf("Nota 1 = %.1lf | ",x[i].n1);
        printf("Nota 2 = %.1lf\n",x[i].n2);

    }
    SelectionSort(x,N);

    printf("\n");
    int a=0;
    printf("Alunos ordenados pela nota 1:\n");
    for(i=0;i<N;i++)
    {
        printf("Aluno %d:\n",i+1);
        printf("Nome = %s\n",x[i].nome);
        printf("Nota 1 = %.1lf | ",x[i].n1);
        printf("Nota 2 = %.1lf\n",x[i].n2);

        double media = (x[i].n1 + x[i].n2) /2.0;

        if(media<7.0)
        {
            memset(x[a].aprovados,0,sizeof(x[a].aprovados));
            strcat( x[a++].aprovados , x[i].nome);
        }

    }
    InsertionSort2(x,a);
    printf("\n");
     printf("Alunos reprovados em ordem alfabética!\n");
     for(i =0;i<a;i++)
        printf("%s\n",x[i].aprovados);

}
