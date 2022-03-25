#include<bits/stdc++.h>
using namespace std;

// 1 -> even
// 0 -> odd
bool isEven(int a){
    // odd
    if(a&1){
        return 0;
    }
    return 1;
}

int main()
{
    int num;
    cin>>num;

    if(isEven(num)){
        cout<<num<<" is Even"<<endl;
    }
    else{
        cout<<num<<" is Odd"<<endl;
    }
    return 0;
}