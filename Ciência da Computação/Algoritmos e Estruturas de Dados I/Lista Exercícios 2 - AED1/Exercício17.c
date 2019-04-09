// Feito por Samuel Eduardo da Silva
#include<stdio.h>
#include<conio.h>
#include <locale.h>
#include<math.h>

int main(){
    float SI,SF,VHT,HT,AUX;
    int C,Cat,Turn;
    setlocale(LC_ALL,"Portuguese");
    printf("Xxxxxxxxxxxxxx-Programa para cálculo de salário do funcionário-xxxxxxxxxxxxxxX!\n\n\n");
    printf("Turnos: 1 - Matutino. | 2 - Vespertino. | 3 - Noturno.\n\n");
    printf("Categorias: 10 - Operário. | 20 - Gerente.\n\n\n\n");
    printf("Digite o código do funcionário:\n");
    scanf("%i",&C);
    printf("Digite o número de horas trabalhadas:\n");
    scanf("%f",&HT);
    printf("Digite o turno do funcionário:\n");
    scanf("%i",&Turn);
    printf("Digite a categoria do funcionário:\n");
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
                   printf("\nOpção de turno inválida!\n");
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
                    printf("\nOpção de turno inválida!\n");
                    }
         break;
         default:
             printf("\nOpção(ões) inválida(s)!\n");
    }
    if (SI<=300)
        AUX=SI*0.2;
    else if ((SI>300)&&(SI<=600))
        AUX=SI*0.15;
    else
        AUX=SI*0.05;
    SF=AUX+SI;
    if (SF>=1)
    printf("\n\n--> O funcionário de código:%i ,irá receber um salário de:R$%.2f <--",C,SF);
    else
    printf("\n\nDados incorretos!!");
    getch();
    return 0;
}

