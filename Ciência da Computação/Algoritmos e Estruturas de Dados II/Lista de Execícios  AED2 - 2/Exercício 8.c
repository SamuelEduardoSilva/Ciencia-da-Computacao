#include<stdio.h>
#include<stdbool.h>
#include<math.h>
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

int DIVS(int N,int *max,int *min)
{
    int Menor=-1;


    if(EhPrimo(N))
        return 1;

    else
    {
        int i=2;
        for(;i<N;i++)
        {
            if(N%i==0)
            {
                if(Menor==-1)
                {
                    *min=i;
                     *max=i;
                    Menor=0;
                }

                else
                {
                    *max=i;

                }


            }
        }


        return 0;
    }


}


int main()
{
    int N,MaiorDivisor,MenorDivisor;

    scanf("%d",&N);

    if(!DIVS(N,&MaiorDivisor,&MenorDivisor))
    {
        printf("O numero nao eh primo!\n");
        printf("Menor divisor = %d\n",MenorDivisor);
        printf("Maior divisor = %d\n",MaiorDivisor);
    }
    else
        printf("Primo!\n");
}
