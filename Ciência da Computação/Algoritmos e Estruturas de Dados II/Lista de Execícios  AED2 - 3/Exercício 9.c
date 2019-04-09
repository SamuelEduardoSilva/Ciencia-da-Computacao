#include<stdio.h>
#include<stdlib.h>

typedef struct
{

    char Nome[50];
    int Dia;
    int Mes;

}Pessoas;


int main()
{

    Pessoas **x = (Pessoas**) malloc(40*sizeof(Pessoas*));
    char Meses[13][50] = {"o","Janeiro","Fevereiro","Março","Abril","Maio","Junho","Julho","Agosto","Setembro","Outubro","Novembro","Dezembro"};
    int i;

    for(i=0;i<40;i++)
       x[i] = (Pessoas*) malloc(sizeof(Pessoas));

    printf("Digite os dados das pessoas:\n\n");

    for(i=0;i<40;i++)
    {
        printf("Pessoa %d: \n",i+1);

        printf("Nome = ");
        scanf("%50[^\n]",x[i]->Nome);
        getchar();
        printf("Mes do Aniversario = ");
        scanf("%d",&x[i]->Mes);
        getchar();
        printf("Dia do Aniversario = ");
        scanf("%d",&x[i]->Dia);
        getchar();
    }
    int j;

    printf("\n");

    for(i=1;i<=12;i++)
    {
        printf("%s:\n",Meses[i]);
        for(j=0;j<40;j++)
        {
            if(x[j]->Mes == i)
            {
                printf("%s\n",x[j]->Nome);
                printf("Dia = %d\n",x[j]->Dia);
            }
        }
        printf("\n");
    }
    for(i=0;i<40;i++)
        free(x[i]);

    free(x);

    return 0;
}
