#include<stdio.h>
#include<locale.h>
struct R
{
    char N[50];
    int I;
    double S;
};

int main()
{
    setlocale(LC_ALL,"Portuguese");
    struct R X[10];
    int i;

    for(i=0;i<10;i++)
    {
        printf("Digite o nome da %d� pessoa: ",i+1);
        scanf("%50[^\n]",X[i].N);
        getchar();
        printf("Digite a idade da %d� pessoa: ",i+1);
        scanf("%d",&X[i].I);
        getchar();
        printf("Digite o sal�rio da %d� pessoa: ",i+1);
        scanf("%lf",&X[i].S);
        getchar();
    }
    for(i=0;i<10;i++)
    {

        printf("%d� Nome = %s\n",i+1,X[i].N);
        printf("%d� Idade = %d\n",i+1,X[i].I);
        printf("%d� Sal�rio = %.2lf\n",i+1,X[i].S);
    }
}
