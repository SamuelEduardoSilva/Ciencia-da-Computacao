#include<stdio.h>
#include<locale.h>
struct R
{
    long long int M;
    char N[50];
    double N1,N2;
};

int main()
{
    setlocale(LC_ALL,"Portuguese");
    struct R X[25];
    int i;
    char Sit[25];
    for(i=0;i<25;i++)
    {
        printf("Digite a matricula da %dº pessoa: ",i+1);
        scanf("%lli",&X[i].M);
        getchar();
        printf("Digite o nome da %dº pessoa: ",i+1);
        scanf("%50[^\n]",X[i].N);
        getchar();
        printf("Digite a nota 1 da %dº pessoa: ",i+1);
        scanf("%lf",&X[i].N1);
        getchar();
        printf("Digite a nota 2 da %dº pessoa: ",i+1);
        scanf("%lf",&X[i].N2);
        getchar();
        if(((X[i].N1 + X[i].N2 )/ 2.0) >=6.0)
            Sit[i]='A';
        else
            Sit[i]='R';
    }
    printf("Matrícula\tNome\tNota-1\tNota-2\t\tSituação:\n");
    for(i=0;i<25;i++)
    {
        printf("%lli\t%s\t%.1lf\t%.1lf\t\t%c\n",X[i].M,X[i].N,X[i].N1,X[i].N2,Sit[i]);


    }
}
