#include<stdio.h>
#include<string.h>

int Vets(int X[])
{
    int i;
    int Y[30];
    int a=0;
    memset(Y,0,sizeof(Y));
    for(i=0;i<30;i++)
    {
        if(X[i]<0)
        {
            Y[a]=X[i];
            a++;
        }
    }
    return a;
}


int main()
{
    int X[30];
    int i;
    int o=0;
    printf("Preencha aqui o vetor:\n");
    for(i=0;i<30;i++)
    {
        scanf("%d",&X[i]);

    }

    printf("A quantidade de valores do vetor Y eh: %d", Vets(X));
}
