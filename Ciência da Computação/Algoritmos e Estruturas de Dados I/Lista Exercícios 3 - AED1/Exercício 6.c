//Feito por Samuel Eduardo da Silva
#include<stdio.h>

main(){
   int i,N,menor=32767,maior=-32767;
   for (i=0;i<10;i++){
    printf("Digite um numero:\n");
    scanf("%i",&N);
    if (N<menor)
        menor=N;
    if (N>maior)
        maior=N;


   }
   printf("O menor valor eh %i\n",menor);
   printf("O maior valor eh %i\n",maior);

}
