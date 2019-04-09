// Feito por Samuel Eduardo da Silva
#include<stdio.h>
#include<conio.h>
#include<locale.h>

int main(){
    int OP,N;
    setlocale(LC_ALL,"Portuguese");
    printf("Menu de opcões:\n\n");
    printf("1 - Verificar se é par ou ímpar.\n");
    printf("2 - Verificar se é positivo, negativo ou zero.\n");
    printf("3 - Verificar se é divisível por 6.\n\n");
    printf("Digite a opção desejada:");
    scanf("%i",&OP);
    printf("Digite um número:");
    scanf("%i",&N);
    switch (OP){
        case 1: if (N%2==0)
                    printf("O número é par!\n");
                else
                    printf("o número é impar!\n");
                break;
        case 2: if (N>0)
                    printf("O número é positivo!\n");
                else if (N==0)
                    printf("O número é igual a zero!\n");
                else
                    printf("O número digitado é negativo!\n");
                break;
        case 3: if (N%6==0)
                    printf("O número é divisivel por 6!\n");
                else
                    printf("O número não é divisivel por 6!\n");
                break;
        default:
            printf("Opção inválida!\n");
}
 getch();
 return 0;
}
