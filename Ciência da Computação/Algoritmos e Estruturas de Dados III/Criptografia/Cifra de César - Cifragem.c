#include<stdio.h>
#include<string.h>
int main(){

    char Text[50];
    int Chave;
    int N;
    int i,j;
    printf("Digite quantas mensagens quer criptografar:\n");
    scanf("%d",&N);
    for(j=0;j<N;j++)
    {
      printf("Digite o texto a ser criptografado: ");

      scanf("%s",&Text);
      getchar();

      printf("Digite a chave utilizada: ");
      scanf("%d",&Chave);
      getchar();

      printf("Mensagem criptografada:\n");
      for(i=0;i<strlen(Text);i++)
      {
          int enc=(int)Text[i]+Chave;
          if (enc>90)
            enc=enc-26;
          printf("%c",(char)enc);
      }
       printf("\n");
    }

}


