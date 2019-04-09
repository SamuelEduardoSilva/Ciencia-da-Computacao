#include<stdio.h>
#include<locale.h>
struct R
{
    long long int C;
    char E[50];
    int H;
};

int main()
{
    setlocale(LC_ALL,"Portuguese");
    struct R X[5];
    int i;
    double P[5];

    for(i=0;i<5;i++)
    {
        printf("Digite o código do %dº cliente:\n",i+1);
        scanf("%lli",&X[i].C);
        getchar();
        printf("Digite o e-mail do %dº cliente:\n",i+1);
        scanf("%s",&X[i].E);
        getchar();
        printf("Digite as horas de uso do %dº cliente:\n",i+1);
        scanf("%d",&X[i].H);
        getchar();
        if(X[i].H>20)
        P[i]=((X[i].H-20)*2.5)+35.0;
        else
            P[i]=35.0;
    }
    printf("\t\tRelatório de pagamento:\n\n");
    printf("Código\tE-Mail\t\t\t    Horas\t\tTotal a pagar\n");
    for(i=0;i<5;i++)
    {
        printf("%lli %s\t%d\t\t%.2lf\n",X[i].C,X[i].E,X[i].H,P[i]);
    }
}
