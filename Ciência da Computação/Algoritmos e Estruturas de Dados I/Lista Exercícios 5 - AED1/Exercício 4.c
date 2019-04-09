// Feito por Samuel Eduardo da Silva
#include<stdio.h>
#include<math.h>
int main(){
   float s=1,xr,x;
   int i,cont=1,f=2;
   unsigned long long fat=1;
   printf("Digite o valor em graus:\n");
   scanf("%f",&x);
   xr=(x*3.1415926536)/180.0;
   do{
    fat=1;
    for (i=f;i>1;i--){
        fat=i*fat;
    }
        if(cont%2==1)
            s-=pow(xr,f)/fat;
        else
            s+=pow(xr,f)/fat;

    f+=2;
    cont++;
   }while(cont<=10);
   printf("O valor do cosseno eh:%.2f",s);
   return 0;
}
