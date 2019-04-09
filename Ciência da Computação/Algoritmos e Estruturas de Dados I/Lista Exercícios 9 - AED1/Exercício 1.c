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
        printf("Digite o nome da %dº pessoa: ",i+1);
        scanf("%50[^\n]",X[i].N);
        getchar();
        printf("Digite a idade da %dº pessoa: ",i+1);
        scanf("%d",&X[i].I);
        getchar();
        printf("Digite o salário da %dº pessoa: ",i+1);
        scanf("%lf",&X[i].S);
        getchar();
    }
    for(i=0;i<10;i++)
    {

        printf("%dº Nome = %s\n",i+1,X[i].N);
        printf("%dº Idade = %d\n",i+1,X[i].I);
        printf("%dº Salário = %.2lf\n",i+1,X[i].S);
    }
}
