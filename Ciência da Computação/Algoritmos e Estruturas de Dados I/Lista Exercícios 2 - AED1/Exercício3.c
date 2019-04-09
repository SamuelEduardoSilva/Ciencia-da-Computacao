// Feito por Samuel Eduardo da Silva
#include<stdio.h>
#include<conio.h>
#include<locale.h>

int main(){
    int N1,N2;
    setlocale(LC_ALL,"Portuguese");
    printf("Digite um número:\n");
    scanf("%i",&N1);
    printf("Digite um segundo numero,diferente do primeiro já digitado:\n");
    scanf("%i",&N2);
    if (N1>N2)
        printf("O primeiro número digitado e maior que o segundo!\n");
    else
        printf("O segundo número digitado é maior que o primeiro!\n");
    getch();
    return 0;
}
