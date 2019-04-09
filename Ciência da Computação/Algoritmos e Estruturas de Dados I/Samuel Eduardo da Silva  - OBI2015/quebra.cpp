#include<iostream>

using namespace std;


int main()
{

    int X;
    cin>>X;
    int N1[X],N2[X];
    char L[X];
    int i,j,l,k,v=1;
    char P[X];
    for(i=0;i<X;i++)
    {
        cin>>N1[i]>>L[i]>>N2[i];
    }



    for(i=0;i<X;i++){
        if(N1[i]==0)
            P[0]=L[i];

        if(N2[i]==1)
            P[X-1]=L[i];
   }

        v=1;

        for(l=0;l<X;l++){
                for(k=1;k<X;k++){
                    if(N2[l]==N1[k]){
                        P[v]=L[k];
                        v++;
                    }
                }
            }



    for(i=0;i<X;i++){
    cout<<P[i];
    }
    cout<<endl;

}
