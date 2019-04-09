#include<stdio.h>

int Soma(int X[5][5])
{
    int i,j;
    int soma=0;
    for(i=0;i<5;i++){
        for(j=0;j<5;j++)
        {
            soma+=X[i][j];
        }
    }
    return soma;
}


int main()
{
    int M[5][5];
    int i,j;
    printf("Preencha aqui a matriz:\n");
    for(i=0;i<5;i++){
        for(j=0;j<5;j++)
        {
            scanf("%d",&M[i][j]);
        }
    }
    printf("A soma dos elementros dessa matriz eh: %d\n",Soma(M));
}
