// Feito por Samuel Eduardo da Silva
#include<stdio.h>
#include<conio.h>
#include <locale.h>

int main(){
    int R1,R2,R3,Cont=0;
    setlocale(LC_ALL,"Portuguese");
    printf("Xxxxxxxx Programa para corre��o das respostas xxxxxxxX\n\n\n\n");
    printf("Quest�o 1: Alternativas - 1 | 2 | 3 | 4\n");
    printf("Digite a resposta da Quest�o 1:\n");
    scanf("%i",&R1);
    printf("Quest�o 2: Alternativas - 1 | 2 | 3 | 4\n");
    printf("Digite a resposta da Quest�o 2:\n");
    scanf("%i",&R2);
    printf("Quest�o 3: Alternativas - 1 | 2 | 3 | 4\n");
    printf("Digite a resposta da Quest�o 3:\n");
    scanf("%i",&R3);

    printf("------------GABARITO------------\nReposta Quest�o 1= (1)\nReposta Quest�o 2= (3)\nReposta Quest�o 3= (2)\n\n\n");


    switch (R1){
     case 1:
     printf("\nA resposta da primeira quest�o est� correta!");
     Cont=Cont+1;

     break;
     default:
     printf("\nA resposta da primeira quest�o est� incorreta!");

    }
    switch (R2){
      case 3:
      printf("\nA resposta da segunda quest�o est� correta!");
      Cont=Cont+1;
      break;
      default:
      printf("\nA resposta da segunda quest�o est� incorreta!");

    }
    switch (R3){
      case 2:
      printf("\nA resposta da terceira quest�o est� correta!");
      Cont=Cont+1;
      break;
      default:
      printf("\nA resposta da terceira quest�o est� incorreta!");

    }
    printf("\n\n-->Voc� acertou %i quest�o(es)!",Cont);

    getch();
    return 0;
}
