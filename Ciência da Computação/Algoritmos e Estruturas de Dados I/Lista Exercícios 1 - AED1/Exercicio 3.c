//Feito por Samuel Eduardo da Silva
#include<stdio.h>
#include<locale.h>

int main(){
    float PP,NPP;
    setlocale(LC_ALL,"Portuguese");
    printf("Digite o preço do produto:\n");
    scanf("%f",&PP);
    NPP=PP-(PP*0.10);
    printf("O novo preço do produto é %.2f\n",NPP);
    return 0;
}
