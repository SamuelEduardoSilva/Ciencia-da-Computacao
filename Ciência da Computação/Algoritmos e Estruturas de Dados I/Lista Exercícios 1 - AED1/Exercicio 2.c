//Feito por Samuel Eduardo da Silva
#include<stdio.h>
#include<locale.h>

int main(){
    float N1,N2,D;
    setlocale(LC_ALL,"Portuguese");
    printf("Digite o primeiro número: \n");
    scanf("%f",&N1);
    printf("Digite o segundo número: \n");
    scanf("%f",&N2);
    D=N1/N2;
    printf("O resultado da divisão é: %.2f \n",D);
    return 0;

}
