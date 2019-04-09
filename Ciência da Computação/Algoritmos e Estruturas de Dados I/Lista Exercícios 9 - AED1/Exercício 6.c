#include<stdio.h>
#include<locale.h>
#include<stdbool.h>
struct R
{
    char N[50];
    int D;
    int M;
};

int main()
{
    setlocale(LC_ALL,"Portuguese");
    struct R X[40];
    int i,j;
    bool Y=false;
    char Mes[12][50]={"Janeiro","Fevereiro","Março","Abril","Maio","Junho","Julho","Agosto","Setembro","Outubro","Novembro","Dezembro"};
    for(i=0;i<40;i++)
    {
        printf("Digite o nome da %dº pessoa:\n",i+1);
        scanf("%50[^\n]",X[i].N);
        getchar();
        printf("Digite o dia do aniversário da %dº pessoa:\n",i+1);
        scanf("%d",&X[i].D);
        getchar();
        printf("Digite o mês do aniversário da %dº pessoa:\n",i+1);
        scanf("%d",&X[i].M);
        getchar();
    }
    for(j=0;j<12;j++)
    {

   printf("%s: \n",Mes[j]);

        for(i=0;i<40;i++)
        {
            if(X[i].M==j+1){
            printf("Nome = %s | Dia = %d\n",X[i].N,X[i].D);
            Y=true;
            }
        }
        if(!Y)
            printf("Não há aniversáriantes nesse mês!\n\n");
        Y=false;
        printf("\n");
    }
}
