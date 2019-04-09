//Feito por Samuel Eduardo da Silva
#include<stdio.h>
#include<conio.h>
#include<locale.h>

int main(){
    float N1,N2,R;
    setlocale(LC_ALL,"Portuguese");
    printf("Digite o primeiro valor:\n");
    scanf("%f",&N1);
    printf("Digite o segundo valor:\n");
    scanf("%f",&N2);
    R=N1-N2;
    if (R<10)
        printf("O resultado da subtração dos valores digitados é %.2f,portanto é  menor que 10\n",R);
    getch();
    return 0;
}

