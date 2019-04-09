// Samuel Eduardo da Silva
#include<stdio.h>
#include<conio.h>
#include<locale.h>

int main(){
    int N;
    setlocale(LC_ALL,"Portuguese");
    printf("Digite um número\n");
    scanf("%i",&N);
    if (N%2==0)
        printf("O número digitado é par");
    else
        printf("O número digitado é impar");
    getch();
    return 0;
}
