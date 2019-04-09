#include<stdio.h>
#include<locale.h>
int main()
{
    setlocale(LC_ALL,"Portuguese");
    int M[6][5];
    int i,j;
    int Soma=0;
    for(i=0;i<6;i++){
        for(j=0;j<5;j++)
        {
            printf("Digite o valor[%d][%d] da matriz:\n",i,j);
            scanf("%d",&M[i][j]);
            if(i%2==0)
                Soma+=M[i][j];
        }
    }

    printf("A soma das linhas pares da matriz é: %d",Soma);
}
