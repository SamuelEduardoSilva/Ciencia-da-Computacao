#include<stdio.h>


int main(){
  int M[5][5];

  int i,j;
  int Soma=0;


  for (i=0;i<5;i++){
    for (j=0;j<5;j++){
        scanf("%d",&M[i][j]);
        if (j>i)
            Soma+=M[i][j];
    }

  }


    printf("%d\n",Soma);


}
