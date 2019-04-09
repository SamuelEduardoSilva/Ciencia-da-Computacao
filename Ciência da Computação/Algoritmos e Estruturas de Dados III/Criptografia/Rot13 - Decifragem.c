#include<stdio.h>
#include<string.h>
int main(){

    char Text[50];
    int Chave;
    int N;
    int i,j;
    printf("Digite quantas mensagens quer descriptografar:\n");
    scanf("%d",&N);
    for(j=0;j<N;j++)
    {
      printf("Digite o texto a ser descriptografado: ");

      scanf("%s",&Text);
      getchar();

      Chave = 13;

      printf("Mensagem descriptografada:\n");
      for(i=0;i<strlen(Text);i++)
      {
          int enc=(int)Text[i]-Chave;
          if (enc<65)
            enc=enc+26;
          printf("%c",(char)enc);
      }
       printf("\n");
    }

}


