#include<iostream>
using namespace std;

int main()
{
    #ifndef ONLINE_JUDGE
        freopen("input.txt","r",stdin);
        freopen("output.txt","w",stdout);
    #endif

    int n;
    cout<<"Program to find the if a number is even or odd"<<endl;
    cin>>n;

    if(n%2==0){
        cout<<"Even No.";
    }
    else{
        cout<<"Odd No.";
    }
    return 0;
}