// Feito por Samuel Eduardo da Silva
#include<stdio.h>
#include<conio.h>
#include <locale.h>

int main(){
    int L,IV;

    setlocale(LC_ALL,"Portuguese");
    printf("--------Opções de Destino:----------\n\n");
    printf("1-Região Norte || 2-Região Nordeste || 3-Região Centro-Oeste || 4-Região Sul\n\n");
    printf("--------Opções de Viagem:----------\n\n");
    printf("10-Apenas Ida || 20-Ida e Volta\n\n\n\n");
    printf("Digite o destino:\n");
    scanf("%i",&L);
    printf("Digite a opção de viagem:\n");
    scanf("%i",&IV);

    switch (L){
      case 1:
        switch (IV){
        case 10:
        printf("\n\nO valor da passagem é de:R$500,00");
        break;
        case 20:
        printf("\n\nO valor da passagem é de:R$900,00");
        break;
        default:
        printf("\n\nOpção de viagem inválida!\n\n");
        }
      break;
      case 2:
        switch (IV){
        case 10:
        printf("\n\nO valor da passagem é de:R$350,50");
        break;
        case 20:
        printf("\n\nO valor da passagem é de:R$650,00");
        break;
        default:
        printf("\n\nOpção de viagem inválida!\n\n");

        }
       break;
        case 3:
        switch (IV){
        case 10:
        printf("\n\nO valor da passagem é de:R$350,00");
        break;
        case 20:
        printf("\n\nO valor da passagem é de:R$600,00");
        break;
        default:
        printf("\n\nOpção de viagem inválida!\n\n");

        }
        break;
        case 4:
        switch (IV){
        case 10:
        printf("\n\nO valor da passagem é de:R$300,00");
        break;
        case 20:
        printf("\n\nO valor da passagem é de:R$550,00");
        break;
        default:
        printf("\n\nOpção de viagem inválida!\n\n");
            }
        break;
        default:
        printf("\n\nOpção de destino inválida!\n\n");

    }
    getch();
    return 0;

}
