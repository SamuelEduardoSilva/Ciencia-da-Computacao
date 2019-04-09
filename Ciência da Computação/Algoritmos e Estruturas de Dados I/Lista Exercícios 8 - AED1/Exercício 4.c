#include<stdio.h>


int main()
{
    float M[5][5];
    int i,j;
    float D[5];

    for(i=0;i<5;i++)
    {
        for(j=0;j<5;j++)
        {
            printf("Digite o [%d][%d] da matriz:\n",i,j);
            scanf("%f",&M[i][j]);
            if(i==j)
                D[i]=M[i][j];
        }
    }
    for(i=0;i<5;i++)
    {
        for(j=0;j<5;j++){
            M[i][j]*=D[i];
        }
    }
    for(i=0;i<5;i++)
    {
        for(j=0;j<5;j++)
        {
            printf("%.1f  ",M[i][j]);
        }
        printf("\n");
    }
}
