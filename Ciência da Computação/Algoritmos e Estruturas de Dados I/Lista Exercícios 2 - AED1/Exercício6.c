// Feito por Samuel Eduardo da Silva
#include<stdio.h>
#include<conio.h>
#include<locale.h>

int main(){
    int TP;
    float VA,VR;
    setlocale(LC_ALL,"Portuguese");
    printf("Opções de investimento:\n");
    printf("1 - Poupança.\n");
    printf("2 - Fundos de Renda Fixa.\n\n");
    printf("Escolha a opção desejada: ");
    scanf("%i",&TP);
    printf("Digite o valor do investimento: R$");
    scanf("%f",&VA);
    switch (TP){
         case 1:
             VR=VA+(VA*0.006);
             printf("Voce escolheu a opção Poupança!\n");
             printf("O valor corrigido é:%.2f\n",VR);
             break;
         case 2:
             VR=VA+(VA*0.009);
             printf("Voce escolheu a opcao Fundos de Renda Fixa!\n");
             printf("O valor corrigido é:%.2f\n",VR);
             break;
         default:
            printf("opção inválida!");
    }
    getch();
    return 0;
}
