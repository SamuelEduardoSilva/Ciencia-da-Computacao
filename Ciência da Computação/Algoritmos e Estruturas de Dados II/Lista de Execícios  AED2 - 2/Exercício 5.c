#include<stdio.h>
#define ll  long long int
#include<limits.h>
int funtion(ll a ,ll b,ll *s,ll *m)
{
    ll mult;
    ll soma;
    ll x = INT_MAX;
    ll y = -INT_MAX;

    soma=a+b;
    mult=a*b;

    *s=soma;
    *m=mult;


    if(soma> x || mult >  x || soma< y || mult <  y)
        return -1;
    else if (a==b)
        return 1;
    else if (a!=b)
        return 0;
}


int main()
{
    ll a,b;
    ll soma,mult;


    while(scanf("%lld %lld",&a,&b)!=EOF)
    {
        int x = funtion(a,b,&soma,&mult);
        if(x==1)
            printf("Sao iguais!\n");
        else if(x==0)
            printf("Sao diferentes!\n");
        else
        {
            printf("A soma ou multiplicacao estouraram o limite do inteiro!\n");

        }



        printf("Soma = %lld\n",soma);
        printf("Multiplicacao = %lld\n",mult);

    }


}
