// Feito por Samuel Eduardo da Silva
#include<stdio.h>
#include<conio.h>
#include <locale.h>

int main(){
    float P,A,IMC;
    setlocale(LC_ALL,"Portuguese");
    printf("Digite seu peso:\n");
    scanf("%f",&P);
    printf("Digite sua altura:\n");
    scanf("%f",&A);
    IMC = (P/(A*A));
    if (IMC<20)
        printf("\nAbaixo do peso!\n");
    else if ((IMC==20)&&(IMC<25))
        printf("\nPeso normal !\n");
    else if ((IMC>=25)&&(IMC<30))
        printf("\nSobre peso !\n");
    else if ((IMC>=30)&&(IMC<40))
        printf("\nObeso!\n");
    else
        printf("\nObesidade mórbida!\n");
    getch();
    return 0;
}
