#include<iostream>
using namespace std;

int main()
{
    #ifndef ONLINE_JUDGE
        freopen("input.txt","r",stdin);
        freopen("output.txt","w",stdout);
    #endif

    int a, b, c;
    
    cin>>a>>b>>c;

    if(a>b){
        if(a>c){
            cout<<a<<" is the max number of 3";
        }
        else{
            cout<<c<<" is the max number of 3";
        }
    }
    else if(b>a){
        if(b>c){
            cout<<b<<" is the max number of 3";
        }
        else{
            cout<<c<<" is the max number of 3";
        }
    }
    else{
        cout<<c<<" is the max number of 3";
    }
    
    return 0;
}