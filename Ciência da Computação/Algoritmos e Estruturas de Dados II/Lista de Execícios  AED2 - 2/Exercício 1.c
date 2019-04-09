#include<stdio.h>
#include<math.h>
#include<stdbool.h>

int Primos[10002];
int a=0;

bool EhPrimo(int X)
{
    int i;
    if(X==2)
        return true;
    if(X<2 || X%2==0)
        return false;

    for(i=3;i<=sqrt(X);i+=2)
    {
        if(X%i==0)
            return false;
    }
    return true;
}

void GeraPrimos()
{
    int i;
    for(i=1;i<=1000;i++)
    {
        if(EhPrimo(i))
          Primos[a++]=i;

    }

}


int Fatores(int *v,int N,int *X)
{

    *X=0;
    int b=0;
    while(N!=1)
    {

        while(N%Primos[b]==0)
        {



            N/=Primos[b];
            v[(*X)++]=Primos[b];



        }

       b++;
    }



    if(*X>10)
        return 1;
    return 0;
}


int main()
{
    GeraPrimos();

    int N;
    int Fats[1002];
    int *X;

    scanf("%d",&N);



        if(Fatores(Fats,N,&X))
        {
            printf("O numero tem mais de 10 fatores primos!\n");

        }
        else
            printf("O numero nao tem mais de 10 fatores primos\n");



        printf("\nO numero tem %d fatores primos\n",X);

        printf("\n\nSeus fatores primos: ");
        int i;
        for(i=0;i<X;i++)
        {
            printf("%d ",Fats[i]);
        }
        printf("\n\n");



}
