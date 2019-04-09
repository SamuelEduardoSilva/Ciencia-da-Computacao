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
            digramas[cript] = ori;
        }
    }

    printf("Digite a memsagem a ser descriptografada: ");
    char text[50];
    scanf("%s",text);

    string aux = "";
    string saida = "";
    int cont = 0;
    for(int i = 0 ; i < strlen(text) ; i++)
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

    cout<<"Mensagem descriptografada: "<<saida<<endl;


}
