#include<stdio.h>

int main(){
     int N[1000];
     int T;
     int i;
     printf("Digite o valor de T: ");
     scanf("%d",&T);
     for (i=0;i<100;i++){
        N[i]=i%T;
     }
     for (i=0;i<100;i++){
        printf("N[%d] = %d\n",N[i],i);
     }
     return 0;
}
