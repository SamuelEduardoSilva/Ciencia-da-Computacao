#include<stdio.h>
#include<stdlib.h>


int main()
{

    int A,B;

    printf("Difina as dimensoes das matrizes:\n");
    scanf("%d %d",&A,&B);

    int **M1 = (int **)malloc(A*sizeof(int *));
    int **M2 = (int **)malloc(A*sizeof(int *));
    int i=0;
    for(;i<B;i++)
    {
        M1[i] = (int *)malloc(B*sizeof(int));
        M2[i] = (int *)malloc(B*sizeof(int));
    }
    int j=0,k=0;
    printf("\nPreencha a primeira matriz:\n");
    for(j=0;j<A;j++)
    {
        for(k=0;k<B;k++)
            scanf("%d",&M1[j][k]);

    }
    printf("\nPreencha a segunda matriz:\n");
    for(j=0;j<A;j++)
    {
        for(k=0;k<B;k++)
            scanf("%d",&M2[j][k]);
    }
    printf("\nA soma das matrizes:\n\n");



    for(j=0;j<A;j++)
    {
        for(k=0;k<B;k++)
        {
            printf("%d ",M1[j][k]+M2[j][k]);
        }
        printf("\n");
    }
    for(i=0;i<B;i++)
        free(M1[i]);
    free(M1);
    for(i=0;i<B;i++)
        free(M2[i]);
    free(M2);


    return 0;
}
