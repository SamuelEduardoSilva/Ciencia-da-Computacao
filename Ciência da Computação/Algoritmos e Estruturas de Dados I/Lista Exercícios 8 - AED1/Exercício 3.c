#include<stdio.h>

int main()
{
    int M[3][4];
    int M3X[3][4];
    int i,j;
    printf("Preencha aqui a matriz 3x4:\n");

    for(i=0;i<3;i++)
    {
        for(j=0;j<4;j++)
        {
            scanf("%d",&M[i][j]);
            M3X[i][j]=M[i][j]*3;
        }
    }
    printf("Matriz digitada triplicada:\n");
    for(i=0;i<3;i++)
    {
        for(j=0;j<4;j++)
        {
            printf("%d ",M3X[i][j]);
        }
        printf("\n");
    }
}
