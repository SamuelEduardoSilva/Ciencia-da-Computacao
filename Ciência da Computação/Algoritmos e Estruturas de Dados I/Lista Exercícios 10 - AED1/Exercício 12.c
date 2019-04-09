#include<stdio.h>


double Media(int X[12][12])
{
    int i,j;
    double Me;
    int Soma=0;

    for(i=0;i<12;i++)
    {
        for(j=0;j<12;j++)
        {
            if(j<i)
                Soma+=X[i][j];
        }
    }
    Me=Soma/66.0;
    return Me;

}


int main()
{
    int M[12][12];
    int i,j;

    printf("Preencha aqui a matriz:\n");
    for(i=0;i<12;i++)
    {
        for(j=0;j<12;j++)
        {
            scanf("%d",&M[i][j]);
        }
    }
    printf("A media dos elementos abaixo da diagonal principal eh: %.1lf",Media(M));
}
