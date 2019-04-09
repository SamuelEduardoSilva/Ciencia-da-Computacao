#include<bits/stdc++.h>

using namespace std;

int main()
{
    map<string,string>digramas;


    for(char x = 'A'; x <= 'Z'; x++)
    {
        for(char y = 'A'; y <= 'Z' ; y++)
        {
            string ori = "";
            ori += x;
            ori += y;

            string cript = "";

            int aux1 = (int)x;
            int aux2 = (int)y;

            aux1+=7;
            aux2+=5;
            if(aux1 > 90)
                aux1 -= 26;
            if(aux2 > 90)
                aux2 -= 26;
            cript+=(char)aux1;
            cript+=(char)aux2;
            digramas[ori] = cript;
        }
    }
    char text[50];
    printf("Digite a mensagem a ser criptografada:\n");

    scanf("%s",text);

    int cont = 0 ;
    string aux = "";
    string saida = "";
    for(int i = 0 ; i < strlen(text); i++)
    {

        if(cont == 2)
        {
            cont = 1;

            saida += digramas[aux];
            aux = text[i];
        }
        else
        {
            cont++;
            aux += text[i];
        }

    }
    saida += digramas[aux];



    if(strlen(text) & 1)
        saida+=text[strlen(text)-1];
    cout<<"Mensagem criptografada : "<<saida<<endl;

}
