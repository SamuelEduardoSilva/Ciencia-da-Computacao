// Feito por Samuel Eduardo da Silva
#include<stdio.h>
#include<conio.h>
#include <locale.h>
#include<math.h>

int main(){
    float A,B,C;
    setlocale(LC_ALL,"Portuguese");
    printf("Digite o primeiro valor:\n");
    scanf("%f",&A);
    printf("Digite o segundo valor:\n");
    scanf("%f",&B);
    printf("Digite o terceiro valor:\n");
    scanf("%f",&C);

    if (((A+B)>C) && ((A+C)>B) && ((B+C)>A)){
    printf("\n\nOs n�meros digitados podem ser lados de um tri�ngulo!\n\n");
    if ((A==B)&&(A!=C))
        printf("\n\nO tri�ngulo � is�sceles!");
    else if ((B==C)&&(B!=A))
            printf("\n\nO tri�ngulo � is�sceles!");
    else if ((A==C)&&(A!=B))
            printf("\n\nO tri�ngulo � is�sceles!");
    else if ((A==B)&&(A==C))
            printf("\n\nO tri�ngulo � equil�tero!");
    else
        printf("\n\nO tri�ngulo � escaleno!");
 }

  else
      printf("Os valores n�o podem ser de lados de um tri�ngulo!");
    getch();
    return 0;



}
