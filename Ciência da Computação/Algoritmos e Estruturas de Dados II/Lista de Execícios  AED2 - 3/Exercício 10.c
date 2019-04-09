#include<stdio.h>
#include<stdlib.h>

typedef struct
{
  char Nome[50];
  int Tell;
  double Preco;

}Lojas;

int main()
{

    Lojas **x = (Lojas**) malloc(15*sizeof(Lojas*));

    int i;
    double Total=0;
    for(i=0;i<15;i++)
       x[i] = (Lojas*) malloc(sizeof(Lojas));


    for(i=0;i<15;i++)
    {
        printf("Loja %d :\n",i+1);
        printf("Nome = ");
        scanf("%50[^\n]",x[i]->Nome);
        getchar();
        printf("Telefone = ");
        scanf("%d",&x[i]->Tell);
        getchar();
        printf("Preço = ");
        scanf("%lf",&x[i]->Preco);
        getchar();
        printf("\n");

        Total += x[i]->Preco;
    }

    double Media = Total/15.0;

    printf("\nLoja nas quais o preço foi abaixo da media:\n\n");
    for(i=0;i<15;i++)
    {
        if(x[i]->Preco<Media)
        {
            printf("Nome = %s\n",x[i]->Nome);
            printf("Telefone = %d\n",x[i]->Tell);
            printf("\n");
        }
    }
    for(i=0;i<15;i++)
        free(x[i]);
    free(x);

    return 0;
}
