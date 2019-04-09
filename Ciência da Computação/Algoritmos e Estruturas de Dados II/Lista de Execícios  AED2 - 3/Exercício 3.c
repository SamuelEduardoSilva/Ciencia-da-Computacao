#include<stdio.h>
#include<stdlib.h>


int main()
{

    int *A = (int *) malloc(20*sizeof(int));
    int *B = (int *) malloc(20*sizeof(int));

    printf("Digite o vetor de 20 posicoes:\n");
    int i=0;
    int a=0;

    for(;i<20;i++)
    {
        scanf("%d",&A[i]);
        if(A[i]>0)
            B[a++]=A[i];
    }

    printf("Vetor compactado:\n");
    int j=0;
    for(;j<a;j++)
        printf("%d\n",B[j]);

    free(A);
    free(B);

    return 0;
}
