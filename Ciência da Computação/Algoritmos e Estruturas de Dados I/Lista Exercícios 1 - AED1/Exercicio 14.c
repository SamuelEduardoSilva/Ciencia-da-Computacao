//Feito por Samuel Eduardo da Silva
#include<stdio.h>
#include<locale.h>


int main(){
    float HT,SM,HE,SF;
    setlocale(LC_ALL,"Portuguese");
    printf("Digite o n�mero de horas trabalhadas:\n");
    scanf("%f",&HT);
    printf("Digite o valor do sal�rio m�nimo:\n");
    scanf("%f",&SM);
    printf("Digite o n�mero de horas extras:\n");
    scanf("%f",&HE);
    SF=(HT*(SM*1/8))+(HE*(SM*1/4));
    printf("O sal�rio a receber �:R$%.2f\n",SF);

    return 0;
}
