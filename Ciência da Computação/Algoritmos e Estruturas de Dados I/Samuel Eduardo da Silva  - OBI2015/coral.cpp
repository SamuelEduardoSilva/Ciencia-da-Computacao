#include<iostream>

using namespace std;


int main()
{
    int C1,C2,C3,C4;
    int i;

    cin>>C1>>C2>>C3>>C4;

    if (C1!=C2 && C1==C3 && C1!=C4 && C2!=C3 && C2!=C4 && C3!=C4 )
        cout<<"V"<<endl;
    else if (C1!=C2 && C1!=C3 && C1!=C4 && C2!=C3 && C2==C4 && C3!=C4 )
        cout<<"V"<<endl;

    else
        cout<<"F"<<endl;
}
