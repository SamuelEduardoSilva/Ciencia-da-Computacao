// Feito por Samuel Eduardo da Silva
#include<stdio.h>
#include<conio.h>
#include<locale.h>

int main(){
    int TP;
    float VA,VR;
    setlocale(LC_ALL,"Portuguese");
    printf("Op��es de investimento:\n");
    printf("1 - Poupan�a.\n");
    printf("2 - Fundos de Renda Fixa.\n\n");
    printf("Escolha a op��o desejada: ");
    scanf("%i",&TP);
    printf("Digite o valor do investimento: R$");
    scanf("%f",&VA);
    switch (TP){
         case 1:
             VR=VA+(VA*0.006);
             printf("Voce escolheu a op��o Poupan�a!\n");
             printf("O valor corrigido �:%.2f\n",VR);
             break;
         case 2:
             VR=VA+(VA*0.009);
             printf("Voce escolheu a opcao Fundos de Renda Fixa!\n");
             printf("O valor corrigido �:%.2f\n",VR);
             break;
         default:
            printf("op��o inv�lida!");
    }
    getch();
    return 0;
}
