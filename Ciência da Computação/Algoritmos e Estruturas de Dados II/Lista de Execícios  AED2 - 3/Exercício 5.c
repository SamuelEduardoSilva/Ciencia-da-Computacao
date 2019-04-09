#include<stdio.h>
#include<stdlib.h>


int main()
{
    int **M1 = (int **)malloc(3*sizeof(int *));
    int i,j;
    for(i=0;i<4;i++)
        M1[i] = (int *)malloc(4*sizeof(int));

    for(i=0;i<3;i++)
    {
        for(j=0;j<4;j++)
            scanf("%d",&M1[i][j]);
    }
    printf("\nMatriz tripla da matriz digitada:\n\n");
    for(i=0;i<3;i++)
    {
        for(j=0;j<4;j++)
            printf("%d ",M1[i][j]*3);
        printf("\n");
    }
    for(i=0;i<4;i++)
        free(M1[i]);
    free(M1);
}
