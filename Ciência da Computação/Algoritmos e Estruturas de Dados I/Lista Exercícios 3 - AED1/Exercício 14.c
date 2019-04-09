//Feito por Samuel Eduardo da Silva
#include<stdio.h>
#include<locale.h>

main(){
    setlocale(LC_ALL,"Portuguese");
   int N,i,somaPares=0,somaPrimos=0,j=0,cont=0;
   printf("Digite 10 números:\n");
   for (i=0;i<10;i++){
    scanf("%i",&N);

    if (N%2==0){
        somaPares+=N;
    }
    for(j=2;j<=N;j++){
                if(N%j==0){
                    cont++;
     }
     }
    if(cont==1){
    somaPrimos+=N;

    }
    cont=0;
   }
   printf("Soma dos números pares:%i\n",somaPares);
   printf("Soma dos números primos:%i\n",somaPrimos);
}
