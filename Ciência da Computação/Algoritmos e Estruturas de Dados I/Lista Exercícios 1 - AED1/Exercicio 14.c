//Feito por Samuel Eduardo da Silva
#include<stdio.h>
#include<locale.h>


int main(){
    float HT,SM,HE,SF;
    setlocale(LC_ALL,"Portuguese");
    printf("Digite o número de horas trabalhadas:\n");
    scanf("%f",&HT);
    printf("Digite o valor do salário mínimo:\n");
    scanf("%f",&SM);
    printf("Digite o número de horas extras:\n");
    scanf("%f",&HE);
    SF=(HT*(SM*1/8))+(HE*(SM*1/4));
    printf("O salário a receber é:R$%.2f\n",SF);

    return 0;
}
