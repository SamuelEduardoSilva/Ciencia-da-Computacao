// Feito por Samuel Eduardo da Silva
#include<stdio.h>
#include<conio.h>
#include<locale.h>
int main(){
    int N;
    setlocale(LC_ALL,"Portuguese");
    printf("Digite um n�mero:\n");
    scanf("%i",&N);
    if (N<15)
        printf("O n�mero %i digitado � menor que 15",N);
    getch();
    return 0;

}
