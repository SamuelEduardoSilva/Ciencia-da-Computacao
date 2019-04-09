#include<stdio.h>
#include<locale.h>
int main()
{
    setlocale(LC_ALL,"Portuguese");

    int M[4][4];
    int i,j;
    int VM[4]={-1,-1,-1,-1};

    for(i=0;i<4;i++){
        for(j=0;j<4;j++){
            printf("Digite o valor [%d][%d] da matriz:\n",i,j);
            scanf("%d",&M[i][j]);
            if(M[i][j]>VM[i])
                VM[i]=M[i][j];
        }
    }

    printf("Os maiores valores de cada linha são:\n");
    for(i=0;i<4;i++)
    {
        printf("Linha %d = %d\n",i,VM[i]);
    }
}
