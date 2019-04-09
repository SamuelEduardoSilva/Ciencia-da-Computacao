#include<locale.h>
#include<stdio.h>
#include<stdbool.h>
int main()
{
    setlocale(LC_ALL,"Portuguese");
    int  M[5][5];
    int i,j;
    int X;
    int flag=false;
    for(i=0;i<5;i++){
        for(j=0;j<5;j++){
            printf("Digite o valor [%d][%d] da matriz:\n",i,j);
            scanf("%d",&M[i][j]);
        }
    }
    printf("Digite o valor de X:\n");
    scanf("%d",&X);
    for(i=0;i<5;i++){
        for(j=0;j<5;j++){
            if(X==M[i][j]){
                printf("\n\nO valor de X,correspodende ao valor da linha %d e coluna %d da matriz!\n",i,j);
                flag=true;
            }
        }
    }
    if(flag==false)
        printf("Não encontrado o valor de X,na matriz!\n");

}
