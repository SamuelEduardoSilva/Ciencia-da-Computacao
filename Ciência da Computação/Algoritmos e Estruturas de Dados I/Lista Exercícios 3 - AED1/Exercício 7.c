//Feito por Samuel Eduardo da Silva
#include<stdio.h>
#define ll long long
int main(){
    int N,X,cont,i,j=0;
    printf("Digite o numero de caso a serem testados: ");
    scanf("%d",&N);
    while(j<N){
        scanf("%d",&X);
        cont=0;
        if(X==1){
            printf("%i nao eh primo\n",X);
        }
        else{
            for(i=1;i<X+1;i++){
                if(X%i==0){
                    cont++;
                }
            }
            if(cont>2){
                printf("%i nao eh primo\n",X);
            }
            else{
                printf("%i eh primo\n",X);
            }
        }
        j++;
    }

return 0;
}
