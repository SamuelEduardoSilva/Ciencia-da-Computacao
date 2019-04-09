#include<stdio.h>
#include<locale.h>
int main()
{
    setlocale(LC_ALL,"Portuguese");
    float M[5][4];
    int i,j;
    float TF[5]={0,0,0,0,0};
    float TS[5]={0,0,0,0,0};
    float TT=0;
    printf("Vendas:\n\n");
    for(i=0;i<5;i++){
            printf("%dº funcionário:\n",i+1);
        for(j=0;j<4;j++)
        {
            printf("%dº semana : R$",j+1);
            scanf("%f",&M[i][j]);
            TT+=M[i][j];
            TF[i]+=M[i][j];
            TS[j]+=M[i][j];
        }
        printf("\n");
    }
    printf("\n\nTotal de vendas do mês:\n\n");
    for(i=0;i<5;i++)
    {
        printf("Funcionário %d: R$%.2f\n",i+1,TF[i]);
    }
    printf("\n\nTotal de vendas de cada semana:\n\n");
    for(i=0;i<4;i++)
    {
        printf("Semana %d: R$%.2f\n",i+1,TS[i]);
    }
    printf("\n\nTotal de vendas do mês: %.2f\n",TT);
    return 0;
}
