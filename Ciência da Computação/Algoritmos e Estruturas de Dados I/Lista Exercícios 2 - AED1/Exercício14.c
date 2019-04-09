// Feito por Samuel Eduardo da Silva
#include<stdio.h>
#include<conio.h>
#include <locale.h>

int main(){
    float N1,N2,M;
    setlocale(LC_ALL,"Portuguese");
    printf("Digite a primeira nota bimestral:\n");
    scanf("%f",&N1);
    printf("Digite a segunda nota bimestral:\n");
    scanf("%f",&N2);
    M=(N1+N2)/2;
    if (M>=7)
        printf("\nAprovado!\n");
    else if (M<3)
        printf("\nReprovado!\n");
    else
        printf("\nExame!\n");
    getch();
    return 0;
}
