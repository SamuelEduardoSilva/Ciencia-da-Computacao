// Feito por Samuel Eduardo da Silva
#include<stdio.h>
#include<conio.h>
#include <locale.h>

int main(){
    float SB,VP;
    setlocale(LC_ALL, "Portuguese");
    printf("Digite o valor do salário bruto:R$");
    scanf("%f",&SB);
    printf("\nDigite o valor da prestação:R$");
    scanf("%f",&VP);
    if (VP<(SB*0.3))
        printf("\nO empréstimo pode ser consebido!\n");
    else
        printf("\nO empréstimo não pode ser consebido!\n");
    getch();
    return 0;


}
