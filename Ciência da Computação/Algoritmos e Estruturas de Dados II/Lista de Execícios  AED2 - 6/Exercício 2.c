#include<stdio.h>
#include<locale.h>
#include<string.h>

typedef struct
{
    int codigo;
    char desc[100];
    char tipo[50];
    double preco;

}registro;
registro x[1002];

void SelectionSort(registro vet[], int tam)
{
  int i, j, min;
  registro aux;
  for (i = 0; i < (tam-1); i++)
  {
    min = i;
    for (j = (i+1); j < tam; j++)
    {
        if(strcmp(vet[j].tipo, vet[min].tipo)<0)
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
void SelectionSort2(registro vet[], int tam)
{
  int i, j, min;
  registro aux;
  for (i = 0; i < (tam-1); i++)
  {
    min = i;
    for (j = (i+1); j < tam; j++)
    {
        if(vet[j].codigo<vet[min].codigo)
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
    setlocale(LC_ALL,"Portuguese");

    int p = 0;
    int q;


    while(1)
    {
        printf("--- Menu --- \n\n");
        printf("--- Opções:\n\n");
        printf("1 -  Cadastrar produtos na lista (array). \n");
        printf("2 -  Consultar produtos de maneira ordenada por tipo de produto. \n");
        printf("3 -  Consultar produtos de maneira ordenada por código do produto . \n");
        printf("4 -  Remover um produto da lista. \n");
        printf("5 -  Sair. \n\n");
        printf("Digite a opção = ");
        scanf("%d",&p);
        getchar();
        if(p == 5)
            break;

        if(p == 1)
        {

            int i;
            printf("\nDigite quantos produtos deseja cadastrar: ");
            scanf("%d",&q);
            getchar();


            for(i=0;i<q;i++)
            {
                printf("\nDigite o código do produto: ");
                scanf("%d",&x[i].codigo);
                getchar();
                printf("Digite o tipo do produto: ");
                scanf("%50[^\n]",x[i].tipo);
                getchar();
                printf("Digite a descrição do produto: ");
                scanf("%100[^\n]",x[i].desc);
                getchar();
                printf("Digite o preço: R$");
                scanf("%lf",&x[i].preco);
                getchar();

            }
        }
        else if(p == 2)
        {
           SelectionSort(x,q);
           printf("\nProdutos ordenados pelo tipo:\n\n");
           int i;
           for(i=0;i<q;i++)
           {
               printf("Codigo = %d\n",x[i].codigo);
               printf("Tipo = %s\n",x[i].tipo);
               printf("Descrição : ");
               printf("%s\n",x[i].desc);
               printf("Preço = %.2lf\n\n",x[i].preco);
           }
        }
        else if(p == 3)
        {
            SelectionSort2(x,q);
            printf("\nProdutos ordenados pelo codigo:\n\n");
           int i;
           for(i=0;i<q;i++)
           {
               printf("Codigo = %d\n",x[i].codigo);
               printf("Tipo = %s\n",x[i].tipo);
               printf("Descrição : ");
               printf("%s\n",x[i].desc);
               printf("Preço = %.2lf\n\n",x[i].preco);
           }

        }
        else if(p == 4)
        {
            int remove;

            printf("\nDigite o código do produto a ser removido: ");
            scanf("%d",&remove);
            int i;
            int j=-1;
            for(i=0;i<q;i++)
            {
                if(x[i].codigo == remove)
                {

                    for(j=i;i<q-1;i++)
                        x[i] = x[i+1];
                }
            }
            if(j==-1)
                printf("\nCodigo inexistente no registro!\n");
            else
                q--;
        }
        if(q==0)
        {
            printf("\nO REGISTRO ESTÁ VAZIO!\n");
            break;
        }



    }
}
