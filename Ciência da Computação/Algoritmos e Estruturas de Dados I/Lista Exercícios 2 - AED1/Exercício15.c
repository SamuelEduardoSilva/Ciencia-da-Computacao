// Feito por Samuel Eduardo da Silva
#include<stdio.h>
#include<conio.h>
#include <locale.h>

int main(){
    float P,M,E;
    setlocale(LC_ALL,"Portuguese");
    printf("Digite peso dos peixes:\n");
    scanf("%f",&P);

    if (P>50){
        E=(P-50);
        M=E*4.0;
        printf("\nO excesso foi de:%2.f Quilos,portanto o valor da multa �:R$%.2f",E,M);
    }
    else
        printf("\nN�o houve excesso,portanto n�o h� multa!");
    getch();
    return 0;
}
