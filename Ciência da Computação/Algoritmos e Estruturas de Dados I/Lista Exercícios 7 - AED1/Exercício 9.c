#include<stdio.h>
#include<string.h>
#include<locale.h>


int main(){
   setlocale(LC_ALL,"Portuguese");
   char N1[50];
   char N2[50];
   char N3[50];
   int M1,M2,M3;
   printf("Digite a primeira palavra:\n");
   scanf("%50[^\n]",N1);
   getchar();
   printf("Digite a segunda palavra:\n");
   scanf("%50[^\n]",N2);
   getchar();
   printf("Digite a terceira palavra:\n");
   scanf("%50[^\n]",N3);
   getchar();
   M1=strlen(N1);
   M2=strlen(N2);
   M3=strlen(N3);

   if (M1<=M2 && M1<=M3 && M2<=M3)
      printf("%s,%s,%s",N1,N2,N3);
   else if (M1<=M2 && M1<=M3 && M2>=M3)
      printf("%s,%s,%s",N1,N3,N2);
   else if (M2<=M1 && M2<=M3 && M1<=M3)
      printf("%s,%s,%s",N2,N1,N3);
   else if (M2<=M1 && M2<=M3 && M1>=M3)
      printf("%s,%s,%s",N2,N3,N1);
   else if (M3<=M1 && M3<=M2 && M1<=M2)
      printf("%s,%s,%s",N3,N1,N2);
   else
      printf("%s,%s,%s",N3,N2,N1);

}
