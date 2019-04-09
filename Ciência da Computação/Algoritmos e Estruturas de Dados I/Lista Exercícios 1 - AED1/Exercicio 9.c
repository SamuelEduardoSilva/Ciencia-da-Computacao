//Feito por Samuel Eduardo da Silva
#include<stdio.h>
#include<locale.h>

int main(){
    int N,X1,X2,X3,X4,X5,X6,X7,X8,X9;
    setlocale(LC_ALL,"Portuguese");
    printf("Digite um número:\n");
    scanf("%i",&N);
    X1=N*1;
    X2=N*2;
    X3=N*3;
    X4=N*4;
    X5=N*5;
    X6=N*6;
    X7=N*7;
    X8=N*8;
    X9=N*9;
    printf("A tabuada desse numero é:\n");
    printf("%2.i x 1= %2.i\n",N,X1);
    printf("%2.i x 2= %2.i\n",N,X2);
    printf("%2.i x 3= %2.i\n",N,X3);
    printf("%2.i x 4= %2.i\n",N,X4);
    printf("%2.i x 5= %2.i\n",N,X5);
    printf("%2.i x 6= %2.i\n",N,X6);
    printf("%2.i x 7= %2.i\n",N,X7);
    printf("%2.i x 8= %2.i\n",N,X8);
    printf("%2.i x 9= %2.i\n",N,X9);
    return 0;

}
