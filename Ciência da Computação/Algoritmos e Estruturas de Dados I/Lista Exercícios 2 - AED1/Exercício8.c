// Feito por Samuel Eduardo da Silva
#include<stdio.h>
#include<conio.h>
#include <locale.h>

int main(){
    float SB,VP;
    setlocale(LC_ALL, "Portuguese");
    printf("Digite o valor do sal�rio bruto:R$");
    scanf("%f",&SB);
    printf("\nDigite o valor da presta��o:R$");
    scanf("%f",&VP);
    if (VP<(SB*0.3))
        printf("\nO empr�stimo pode ser consebido!\n");
    else
        printf("\nO empr�stimo n�o pode ser consebido!\n");
    getch();
    return 0;


}
