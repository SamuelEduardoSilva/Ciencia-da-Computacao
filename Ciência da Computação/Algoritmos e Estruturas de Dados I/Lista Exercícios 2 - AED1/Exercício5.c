// Feito por Samuel Eduardo da Silva
#include<stdio.h>
#include<conio.h>
#include<locale.h>

int main(){
    int N;
    setlocale(LC_ALL,"Portuguese");
    printf("Digite um número:\n");
    scanf("%i",&N);
    if ((N%3==0)&&(N%7==0))
        printf("O número digitado é divisivel por 3 e por 7!");
    else if (N%3==0)
        printf("O número digitado é divisivel apenas por 3!");
    else if (N%7==0)
        printf("O número digitado é divisivel apenas por 7!");
    else
        printf("O número digitado não e divisível por 3 e por 7!");
    getch();
    return 0;
}

