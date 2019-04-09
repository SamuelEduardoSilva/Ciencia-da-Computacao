//Feito por Samuel Eduardo da Silva
#include<stdio.h>
#include<locale.h>
int main(){

    float N1,N2,N3,M;
    setlocale(LC_ALL,"Portuguese");
    printf("Digite o primeiro número: \n");
    scanf("%f",&N1);
    printf("Digite o segundo número: \n");
    scanf("%f",&N2);
    printf("Digite o terceiro número: \n");
    scanf("%f",&N3);
    M=N1*N2*N3;
    printf("O resultado da multiplicação é %2.f \n",M);
    return 0;

}
