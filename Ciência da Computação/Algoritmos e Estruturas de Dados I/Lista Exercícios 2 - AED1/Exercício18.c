// Feito por Samuel Eduardo da Silva
#include<stdio.h>
#include<conio.h>
#include <locale.h>

int main(){
    int L,IV;

    setlocale(LC_ALL,"Portuguese");
    printf("--------Op��es de Destino:----------\n\n");
    printf("1-Regi�o Norte || 2-Regi�o Nordeste || 3-Regi�o Centro-Oeste || 4-Regi�o Sul\n\n");
    printf("--------Op��es de Viagem:----------\n\n");
    printf("10-Apenas Ida || 20-Ida e Volta\n\n\n\n");
    printf("Digite o destino:\n");
    scanf("%i",&L);
    printf("Digite a op��o de viagem:\n");
    scanf("%i",&IV);

    switch (L){
      case 1:
        switch (IV){
        case 10:
        printf("\n\nO valor da passagem � de:R$500,00");
        break;
        case 20:
        printf("\n\nO valor da passagem � de:R$900,00");
        break;
        default:
        printf("\n\nOp��o de viagem inv�lida!\n\n");
        }
      break;
      case 2:
        switch (IV){
        case 10:
        printf("\n\nO valor da passagem � de:R$350,50");
        break;
        case 20:
        printf("\n\nO valor da passagem � de:R$650,00");
        break;
        default:
        printf("\n\nOp��o de viagem inv�lida!\n\n");

        }
       break;
        case 3:
        switch (IV){
        case 10:
        printf("\n\nO valor da passagem � de:R$350,00");
        break;
        case 20:
        printf("\n\nO valor da passagem � de:R$600,00");
        break;
        default:
        printf("\n\nOp��o de viagem inv�lida!\n\n");

        }
        break;
        case 4:
        switch (IV){
        case 10:
        printf("\n\nO valor da passagem � de:R$300,00");
        break;
        case 20:
        printf("\n\nO valor da passagem � de:R$550,00");
        break;
        default:
        printf("\n\nOp��o de viagem inv�lida!\n\n");
            }
        break;
        default:
        printf("\n\nOp��o de destino inv�lida!\n\n");

    }
    getch();
    return 0;

}
