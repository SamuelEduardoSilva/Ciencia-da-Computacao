// Feito por Samuel Eduardo da Silva
#include<stdio.h>
#include<conio.h>
#include <locale.h>

int main(){
    int Placa,FP;
    setlocale(LC_ALL,"Portuguese");
    printf("Digite a placa:\n->");
    scanf("%i",&Placa);
    FP=Placa%10;
    switch (FP){
     case 1:
        printf("\nA renovação deve ser feita em Janeiro!");
     break;
     case 2:
        printf("\nA renovação deve ser feita em Fevereiro!");
     break;
     case 3:
        printf("\nA renovação deve ser feita em Março!");
     break;
     case 4:
        printf("\nA renovação deve ser feita em Abril!");
     break;
     case 5:
        printf("\nA renovação deve ser feita em Maio!");
     break;
     case 6:
         printf("\nA renovação deve ser feita em Junho!");
     break;
     case 7:
         printf("\nA renovação deve ser feita em Julho!");
     break;
     case 8:
        printf("\nA renovação deve ser feita em Agosto!");
     break;
     case 9:
        printf("\nA renovação deve ser feita em Setembro!");
     break;
     case 0:
        printf("\nA renovação deve ser feita em Outubro!");
     break;
    }
    getch ();
    return 0;
}
