//Feito por Samuel Eduardo da Silva
#include<stdio.h>
#include<locale.h>

int main(){
    int I;
    float B;
    printf("Digite a idade da pessoa:\n");
    scanf("%i",&I);
    B=I*3157600;
    printf("O numero de batidas do coracao dessa pessoa foi: %.f batidas\n",B);
    return 0;
}
