//Feito por Samuel Eduardo da Silva
#include<stdio.h>
#include<locale.h>

int main(){
setlocale(LC_ALL,"Portuguese");
int N,somaPare=0,prodImpar=1;
while (scanf("%i",&N),N>0){
    if (N%2==0)
        somaPare+=N;
    else if (N%2!=0)
        prodImpar*=N;
}
printf("A soma dos pares é:%i\n",somaPare);
printf("O produtdo dos ímpares é:%i\n",prodImpar);
return 0;

}

