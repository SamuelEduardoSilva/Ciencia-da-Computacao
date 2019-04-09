#include<stdio.h>
#include<stdlib.h>


int main()
{
    double **M = (double **) malloc(5*sizeof(double*));
    double Diagonal[5];
    int i,j;
    int a=0;
    for(i=0;i<5;i++)
        M[i] = (double*) malloc(5*sizeof(double));

    printf("Digite a matriz 5 x 5:\n");

    for(i=0;i<5;i++)
    {
        for(j=0;j<5;j++)
        {
            scanf("%lf",&M[i][j]);
            if(j==i)
                Diagonal[a++]=M[i][j];

        }
    }
    printf("\nMatriz agora multiplicada pela diagonal principal:\n");
    for(i=0;i<5;i++)
    {
        for(j=0;j<5;j++)
            printf("%.2lf ",M[i][j]*Diagonal[i]);

        printf("\n");
    }
    for(i=0;i<5;i++)
        free(M[i]);
    free(M);
}
