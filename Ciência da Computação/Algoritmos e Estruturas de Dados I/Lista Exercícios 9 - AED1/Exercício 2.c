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
    int Soma=0;
    double Media;
    int Ma=-1,Me=120;
    for(i=0;i<10;i++)
    {
        printf("Digite o nome da %d� pessoa: ",i+1);
        scanf("%50[^\n]",X[i].N);
        getchar();
        printf("Digite a idade da %d� pessoa: ",i+1);
        scanf("%d",&X[i].I);
        getchar();
        Soma+=X[i].I;
        if(X[i].I>Ma)
            Ma=X[i].I;
        if(X[i].I<Me)
            Me=X[i].I;
        printf("Digite o sal�rio da %d� pessoa: ",i+1);
        scanf("%lf",&X[i].S);
        getchar();
        printf("\n");
    }
    Media=Soma/10.0;
    for(i=0;i<10;i++)
    {

        printf("%d� Nome = %s\n",i+1,X[i].N);
        printf("%d� Idade = %d\n",i+1,X[i].I);
        printf("%d� Sal�rio = %.2lf\n\n\n",i+1,X[i].S);

    }
    printf("A m�dida das idades �: %.1lf\n",Media);
    printf("A maior idade �: %d\n",Ma);
    printf("A menor idade �: %d\n",Me);
}

