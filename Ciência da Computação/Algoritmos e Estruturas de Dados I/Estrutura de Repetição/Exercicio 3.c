#include<stdio.h>
#include<locale.h>

main(){
    setlocale(LC_ALL,"Portuguese");
  int n1,n2,i,mult=0;
  printf("Digite o primeiro numero:\n");
  scanf("%i",&n1);
  printf("Digite o segundo numero:\n");
  scanf("%i",&n2);
  for (i=0;i<n2;i++){
        mult=n1+mult;
 }
 printf("multiplicação = %i\n",mult);

}
