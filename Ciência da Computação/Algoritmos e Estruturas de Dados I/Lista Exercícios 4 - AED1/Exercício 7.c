//Feito por Samuel Eduardo da Silva
#include<stdio.h>
#include<locale.h>

int main(){
setlocale(LC_ALL,"Portuguese");
float Chico=1.5,Juca=1.10;
int temp=0;
while (Juca<=Chico){
    Chico+=0.02;
    Juca+=0.03;
    temp++;
}
printf("Os anos necessários para que Juca ultrapasse Chico,é:%i",temp);
return 0;
}
