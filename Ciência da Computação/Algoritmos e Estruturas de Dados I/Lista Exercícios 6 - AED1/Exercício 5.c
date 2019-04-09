#include<stdio.h>

int main() {
    int i=0, j, inicio=100, X[10], contDiv=0;
    while (i<10) {
        for (j = 1;j<=inicio;j++) {
            if (inicio%j==0)
                contDiv++;
        }
        if (contDiv==2) {
            X[i] = inicio;
            i++;
        }
        inicio++;
        contDiv = 0;
    }
    for (i = 0; i<10; i++)
        printf("X[%i] = %i\n",i,X[i]);
    return 0;
}
