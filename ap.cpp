#include<bits/stdc++.h>
using namespace std;

int ap(int n){
    int ap = 3*n+7;
    return ap;
}

int main()
{
    int n;
    cin>>n;

    cout<<"nth term is "<<ap(n);
    return 0;
}