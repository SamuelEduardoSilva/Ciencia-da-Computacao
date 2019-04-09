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
    double Soma=0;
    double Media;
    double Ma=-1,Me=9999999999;
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
        Soma+=X[i].S;
        if(X[i].S>Ma)
            Ma=X[i].S;
        if(X[i].S<Me)
            Me=X[i].S;
        printf("\n");
    }
    Media=Soma/10.0;
    for(i=0;i<10;i++)
    {

        printf("%dº Nome = %s\n",i+1,X[i].N);
        printf("%dº Idade = %d\n",i+1,X[i].I);
        printf("%dº Salário = %.2lf\n\n\n",i+1,X[i].S);

    }
    printf("A médida das idades é: %.2lf\n",Media);
    printf("A maior idade é: %.2lf\n",Ma);
    printf("A menor idade é: %.2lf\n",Me);
}


