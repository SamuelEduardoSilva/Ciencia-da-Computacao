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
    printf("\n\nOs números digitados podem ser lados de um triângulo!\n\n");
    if ((A==B)&&(A!=C))
        printf("\n\nO triângulo é isósceles!");
    else if ((B==C)&&(B!=A))
            printf("\n\nO triângulo é isósceles!");
    else if ((A==C)&&(A!=B))
            printf("\n\nO triângulo é isósceles!");
    else if ((A==B)&&(A==C))
            printf("\n\nO triângulo é equilátero!");
    else
        printf("\n\nO triângulo é escaleno!");
 }

  else
      printf("Os valores não podem ser de lados de um triângulo!");
    getch();
    return 0;



}
