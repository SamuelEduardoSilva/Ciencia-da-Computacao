#include<iostream>
#include<cstdio>
using namespace std;

int main()
{
    int N;
    int i,j;

    cin>>N;
    char L[N][N];

    for(i=0;i<N;i++)
    {
        for(j=0;j<N;j++)
            cin>>L[i][j];
    }
    for(i=0;i<N;i++){
        for(j=0;j<N;j++)
        {
            if(L[i][j]=='0'){
                while(j>=0 && j!='0' && j<N)
                    (int)j++;

            }
        }
    }
    for(i=0;i<N;i++){
      for(j=0;j<N;j++){
        if(j==N-1)
            printf("%c");
        else
            printf("%c ",L[i][j]);
      }
      printf("\n");
    }
}
