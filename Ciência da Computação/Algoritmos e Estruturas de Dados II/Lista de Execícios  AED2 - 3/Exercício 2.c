#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<math.h>
bool EhPrimo(int X)
{
    if(X%2==0 || X<2)
        return false;
    if(X==2)
        return true;
    int i;
    for( i=3;i<=sqrt(X);i+=2)
    {
        if(X%i==0)
            return false;
    }
    return true;
}

int main()
{

    int *X  = (int *) malloc(10*sizeof(int));

    int cont=0;
    int aux=100;
    while(cont!=10)
    {
        aux++;
        if(EhPrimo(aux))
            X[cont++]=aux;



    }
    int i=0;
    printf("O vetor de primos:\n\n");
    for(;i<10;i++)
        printf("%d\n",X[i]);

     free(X);

     return 0;

}
