// Feito por Samuel Eduardo da Silva
#include<stdio.h>
#include<conio.h>
#include <locale.h>
#include<math.h>

int main(){
    float SI,SF,VHT,HT,AUX;
    int C,Cat,Turn;
    setlocale(LC_ALL,"Portuguese");
    printf("Xxxxxxxxxxxxxx-Programa para c�lculo de sal�rio do funcion�rio-xxxxxxxxxxxxxxX!\n\n\n");
    printf("Turnos: 1 - Matutino. | 2 - Vespertino. | 3 - Noturno.\n\n");
    printf("Categorias: 10 - Oper�rio. | 20 - Gerente.\n\n\n\n");
    printf("Digite o c�digo do funcion�rio:\n");
    scanf("%i",&C);
    printf("Digite o n�mero de horas trabalhadas:\n");
    scanf("%f",&HT);
    printf("Digite o turno do funcion�rio:\n");
    scanf("%i",&Turn);
    printf("Digite a categoria do funcion�rio:\n");
    scanf("%i",&Cat);
    switch (Cat){
        case 20:
            switch (Turn){
               case 3:
                  VHT=(540*0.18);
                  SI=HT*VHT;
                  break;
               case 2:
                   VHT=(540*0.15);
                   SI=HT*VHT;
                   break;
                case 1:
                   VHT=(540*0.15);
                   SI=HT*VHT;
                   break;
               default:
                   printf("\nOp��o de turno inv�lida!\n");
                   }
        break;
        case 10:
            switch (Turn){
                case 3:
                    VHT=(540*0.13);
                    SI=HT*VHT;
                    break;
                case 2:
                    VHT=(540*0.10);
                    SI=HT*VHT;
                    break;
                 case 1:
                    VHT=(540*0.10);
                    SI=HT*VHT;
                    break;
                default:
                    printf("\nOp��o de turno inv�lida!\n");
                    }
         break;
         default:
             printf("\nOp��o(�es) inv�lida(s)!\n");
    }
    if (SI<=300)
        AUX=SI*0.2;
    else if ((SI>300)&&(SI<=600))
        AUX=SI*0.15;
    else
        AUX=SI*0.05;
    SF=AUX+SI;
    if (SF>=1)
    printf("\n\n--> O funcion�rio de c�digo:%i ,ir� receber um sal�rio de:R$%.2f <--",C,SF);
    else
    printf("\n\nDados incorretos!!");
    getch();
    return 0;
}

