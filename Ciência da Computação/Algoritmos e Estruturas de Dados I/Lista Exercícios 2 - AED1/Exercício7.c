// Feito por Samuel Eduardo da Silva
#include<stdio.h>
#include<conio.h>
#include<locale.h>

int main(){
    int OP,N;
    setlocale(LC_ALL,"Portuguese");
    printf("Menu de opc�es:\n\n");
    printf("1 - Verificar se � par ou �mpar.\n");
    printf("2 - Verificar se � positivo, negativo ou zero.\n");
    printf("3 - Verificar se � divis�vel por 6.\n\n");
    printf("Digite a op��o desejada:");
    scanf("%i",&OP);
    printf("Digite um n�mero:");
    scanf("%i",&N);
    switch (OP){
        case 1: if (N%2==0)
                    printf("O n�mero � par!\n");
                else
                    printf("o n�mero � impar!\n");
                break;
        case 2: if (N>0)
                    printf("O n�mero � positivo!\n");
                else if (N==0)
                    printf("O n�mero � igual a zero!\n");
                else
                    printf("O n�mero digitado � negativo!\n");
                break;
        case 3: if (N%6==0)
                    printf("O n�mero � divisivel por 6!\n");
                else
                    printf("O n�mero n�o � divisivel por 6!\n");
                break;
        default:
            printf("Op��o inv�lida!\n");
}
 getch();
 return 0;
}
