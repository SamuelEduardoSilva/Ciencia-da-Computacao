// Samuel Eduardo da Silva
#include<stdio.h>
#include<conio.h>
#include<locale.h>

int main(){
    int N;
    setlocale(LC_ALL,"Portuguese");
    printf("Digite um n�mero\n");
    scanf("%i",&N);
    if (N%2==0)
        printf("O n�mero digitado � par");
    else
        printf("O n�mero digitado � impar");
    getch();
    return 0;
}
