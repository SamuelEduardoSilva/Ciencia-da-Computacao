//Feito por Samuel Eduardo da Silva
#include<stdio.h>
#include<locale.h>

int main(){
    float C,S,V,SF;
    setlocale(LC_ALL,"Portuguese");
    printf("Digite o salário fixo do funcionário:\n");
    scanf("%f",&S);
    printf("Digite o valor de suas vendas:\n");
    scanf("%f",&V);
    C=(V*0.04);
    SF=S+C;
    printf("A comissão desse funcionário foi:%.2f portanto seu salario reajustado é %.2f",C,SF);
    return 0;

}
