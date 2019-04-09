//Feito por Samuel Eduardo da Silva
#include<stdio.h>
#include<locale.h>

int main(){
 setlocale(LC_ALL,"Portuguese");
 int N,i=0,M,menor=32768;

 scanf("%i",&N);
 while (i<N){
    scanf("%i",&M);

    if (M<menor){
        menor=M;
    }
    i++;
 }
 printf("O menor número digitado:%i",menor);
}
