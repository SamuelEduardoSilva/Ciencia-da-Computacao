// Feito por Samuel Eduardo da Silva
#include<stdio.h>
#include<locale.h>
#include<math.h>
int main(){
 double S,S1,S2,PI,Soma1=0,Soma2=0,PI2;
 int i1=3,i2=5,j=0;
 do{
    S1=(1/pow(i1,3));
    i1+=4;
    Soma1+=S1;
    S2=(1/pow(i2,3));
    i2+=5;
    Soma2+=S2;
    j++;
 }while(j<25);
 S=(1-Soma1 )+Soma2;
 PI=cbrt(32-S);
 printf("%lf\n",PI);
 return 0;
}

