#include<stdio.h>
#include<stdlib.h>


int main()
{

    int *p = (int *)malloc(20*sizeof(int));
    int i=0;
    int cont=0;
    printf("Digite os vinte valores:\n\n");

    for(;i<20;i++)
    {
        scanf("%d",&p[i]);
        if(p[i]%2==0)
            cont++;
    }
    printf("%d valores do vetor eram par!\n",cont);
    free(p);
    return 0;
}
