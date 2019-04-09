//Feito por Samuel Eduardo da Silva
#include<stdio.h>
#include<locale.h>

int main(){
    float A,B,C,DELTA;
    setlocale(LC_ALL,"Portuguese");
    printf("Digite o valor de A:\n");
    scanf("%f",&A);
    printf("Digite o valor de B:\n");
    scanf("%f)",&B);
    printf("Digite o valor de C\n");
    scanf("%f",&C);
    DELTA=((B*B)-4*A*C);
    printf("O valor de delta e %.2f",DELTA);
    return 0;


}
