//Feito por Samuel Eduardo da Silva
#include<stdio.h>
#include<locale.h>

int main(){
    float PP,NPP;
    setlocale(LC_ALL,"Portuguese");
    printf("Digite o pre�o do produto:\n");
    scanf("%f",&PP);
    NPP=PP-(PP*0.10);
    printf("O novo pre�o do produto � %.2f\n",NPP);
    return 0;
}
