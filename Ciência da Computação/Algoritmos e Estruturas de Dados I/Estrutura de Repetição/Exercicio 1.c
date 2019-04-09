#include<stdio.h>
#include<locale.h>

main(){
   setlocale(LC_ALL,"Portuguese");
   int cont;
   for (cont=100;cont<=200;cont++){
   if (cont%2!=0)
   printf("%i\n",cont);

   }
}
