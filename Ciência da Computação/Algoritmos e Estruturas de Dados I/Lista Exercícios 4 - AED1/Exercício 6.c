//Feito por Samuel Eduardo da Silva
#include<stdio.h>
#include<locale.h>

int main(){
 setlocale(LC_ALL,"Portuguese");
 int N,contPar=0,contImpar=0,somaPar=0,somaImpar=0,maiorPar=0,menorImpar=100000;
 float mediaPar,mediaImpar;
 while (printf("Digite um n�mero:"),scanf("%i",&N),N>=0){

    if (N%2==0){
        contPar++;
        somaPar+=N;
        if (N>maiorPar)
            maiorPar=N;
    }
    else if (N%2!=0){
        contImpar++;
        somaImpar+=N;
        if (N<menorImpar)
            menorImpar=N;
    }
 }
 mediaPar=somaPar/(float)contPar;
 mediaImpar=somaImpar/(float)contImpar;
 printf("A media dos n�meros pares digitados �:%.2f\n",mediaPar);
 printf("A media dos n�meros �mpares digitados �:%.2f\n",mediaImpar);
 printf("O maior par �:%i\n",maiorPar);
 printf("O menor �mpar �:%i\n",menorImpar);

}
