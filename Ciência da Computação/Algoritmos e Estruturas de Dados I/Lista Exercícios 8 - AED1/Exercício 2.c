#include<stdio.h>

int main()
{
    int M[4][4];

    int i,j;
    int soma=0;
    printf("Preencha aqui a matriz:\n");

    for(i=0;i<4;i++)
    {
        for(j=0;j<4;j++)
        {
            scanf("%d",&M[i][j]);
            if(i==j)
                soma+=M[i][j];
        }
    }
    printf("A soma dos elementos da diagonal principal eh: %d\n",soma);

}
