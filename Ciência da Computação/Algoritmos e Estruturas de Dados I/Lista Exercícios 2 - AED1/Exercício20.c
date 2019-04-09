// Feito por Samuel Eduardo da Silva
#include<stdio.h>
#include<conio.h>
#include <locale.h>

int main(){
    int R1,R2,R3,Cont=0;
    setlocale(LC_ALL,"Portuguese");
    printf("Xxxxxxxx Programa para correção das respostas xxxxxxxX\n\n\n\n");
    printf("Questão 1: Alternativas - 1 | 2 | 3 | 4\n");
    printf("Digite a resposta da Questão 1:\n");
    scanf("%i",&R1);
    printf("Questão 2: Alternativas - 1 | 2 | 3 | 4\n");
    printf("Digite a resposta da Questão 2:\n");
    scanf("%i",&R2);
    printf("Questão 3: Alternativas - 1 | 2 | 3 | 4\n");
    printf("Digite a resposta da Questão 3:\n");
    scanf("%i",&R3);

    printf("------------GABARITO------------\nReposta Questão 1= (1)\nReposta Questão 2= (3)\nReposta Questão 3= (2)\n\n\n");


    switch (R1){
     case 1:
     printf("\nA resposta da primeira questão está correta!");
     Cont=Cont+1;

     break;
     default:
     printf("\nA resposta da primeira questão está incorreta!");

    }
    switch (R2){
      case 3:
      printf("\nA resposta da segunda questão está correta!");
      Cont=Cont+1;
      break;
      default:
      printf("\nA resposta da segunda questão está incorreta!");

    }
    switch (R3){
      case 2:
      printf("\nA resposta da terceira questão está correta!");
      Cont=Cont+1;
      break;
      default:
      printf("\nA resposta da terceira questão está incorreta!");

    }
    printf("\n\n-->Você acertou %i questão(es)!",Cont);

    getch();
    return 0;
}
