#include<stdio.h>
#include<locale.h>
int main(){
    setlocale(LC_ALL,"Portuguese");
    char C[5][50];
    double D[5][5];
    int i,j;
    double KH;

    for(i=0;i<5;i++)
    {
        printf("Digite o nome da %d� cidade:\n",i+1)/
        scanf("%50[^\n]",C[i]);
        getchar();
    }
    printf("Digite aqui as distancias entra as cidades em KM:\n\n\n");
    for(i=0;i<5;i++){
            if(i!=4)
            printf("%s �:\n\n",C[i]);
        for(j=0;j<5;j++){
            if(j==i)
              D[i][j]=0;
            else if(j>i){
            printf("%s: ",C[j]);
            scanf("%lf",&D[i][j]);
            D[j][i]=D[i][j];
            }
        }
        printf("\n");
    }
   printf("\n\nDigite o consumo de combust�vel do ve�culo: (Km/litros)\n");
   scanf("%lf",&KH);
   printf("\n\nDist�ncias e quantidade de combustivel n�cessarios:\n\n");
   for(i=0;i<5;i++){
        printf("%s �:\n\n",C[i]);
    for(j=0;j<5;j++){
        if(i!=j){
        printf("%s : %.1lf Kil�metros | ",C[j],D[i][j]);
        printf("Combustivel necess�rio: %.1lf litros\n",D[i][j]/KH);
        }
    }
    printf("\n");
   }
 return 0;
}

