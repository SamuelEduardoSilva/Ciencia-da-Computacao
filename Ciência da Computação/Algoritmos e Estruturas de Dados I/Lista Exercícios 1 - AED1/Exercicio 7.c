//Feito por Samuel Eduardo da Silva
#include<stdio.h>
#include<locale.h>
int main(){
    float D1,D2,AD;
    printf("Digite o valor da diagonal maior:\n");
    scanf("%f",&D1);
    printf("Digite o valor da diagonal menor:\n");
    scanf("%f",&D2);
    AD=D1/D2;
    printf("O valor da area do logango e %.2f",AD);
    return 0;
}
