// Feito por Samuel Eduardo da Silva
#include<stdio.h>
#include<conio.h>
#include <locale.h>
#include<math.h>

int main(){
    float N1,N2,RAIZ,POT;
    setlocale(LC_ALL,"Portuguese");
    printf("Digite o primeiro n�mero:\n");
    scanf("%f",&N1);
    printf("Digite o segundo n�mero:\n");
    scanf("%f",&N2);

    if ((N1>N2)&&(N1>0)){
        RAIZ=sqrt(N1);
        POT=(N2*N2);
        printf("O quadrado do menor n�mero �: %.1f\n",POT);
        printf("A raiz do maior n�mero �: %.1f\n",RAIZ);
    }
    else if ((N2>N1)&&(N2>0)){
        RAIZ=sqrt(N2);
        POT=(N1*N1);
        printf("O quadrado do menor n�mero �: %.1f\n",POT);
        printf("A raiz do maior n�mero �: %.1f\n",RAIZ);
    }
    else
        printf("N�o � possivel extrair raiz de n�mero negativo");
getch();
return 0;
}
