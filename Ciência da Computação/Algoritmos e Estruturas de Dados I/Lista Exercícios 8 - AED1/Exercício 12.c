#include<stdio.h>
#include<locale.h>
int main()
{
    setlocale(LC_ALL,"Portuguese");
    float P[20][5];
    float M=-1;
    int i,j;
    int k,m;
    printf("Digite aqui os preços dos produtos:\n\n");
    for(i=0;i<20;i++){
            printf("Produto %d:\n",i+1);
        for(j=0;j<5;j++){
            printf("Loja %d:R$",j+1);
            scanf("%f",&P[i][j]);
            if(P[i][j]>M){
                M=P[i][j];
                k=i;
                m=j;
            }
        }
        printf("\n");
    }
    printf("\n\nO produto mais caro foi o %d da loja %d ,com preço de: %.2f\n",k+1,m+1,M);
}
