//Feito por Samuel Eduardo da Silva
#include<stdio.h>
#include<locale.h>

int main(){
    float C,S,V,SF;
    setlocale(LC_ALL,"Portuguese");
    printf("Digite o sal�rio fixo do funcion�rio:\n");
    scanf("%f",&S);
    printf("Digite o valor de suas vendas:\n");
    scanf("%f",&V);
    C=(V*0.04);
    SF=S+C;
    printf("A comiss�o desse funcion�rio foi:%.2f portanto seu salario reajustado � %.2f",C,SF);
    return 0;

}
