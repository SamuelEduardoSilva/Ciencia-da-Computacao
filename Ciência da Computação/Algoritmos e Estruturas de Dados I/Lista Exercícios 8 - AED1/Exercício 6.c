#include<stdio.h>
#include<locale.h>
int main()
{
    setlocale(LC_ALL,"Portuguese");
    float M[7][7];
    float Soma=0;
    int i,j;

    for(i=0;i<7;i++){
        for(j=0;j<7;j++){
            printf("Digite o valor [%d][%d] da matriz:\n",i,j);
            scanf("%f",&M[i][j]);
            if ( j==7-1-i )
                Soma+=M[i][j];

        }
    }

    printf("\n\nA soma dos elementos da diagonal secundária dessa matriz é : %.1f\n",Soma);

}
