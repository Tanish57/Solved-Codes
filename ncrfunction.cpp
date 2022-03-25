#include<bits/stdc++.h>
using namespace std;

int factorial(int n){
    int fact = 1;

    for(int i =1; i<=n;i++){
        fact *= i;
    }
    return fact;
}

int nCr(int n, int r){
    // int num = factorial(n);
    // int denom = factorial(r) * factorial(n-r);
    int ans = (factorial(n))/(factorial(r) * factorial(n-r));
    // int ans = num/denom;
    return ans;
}

int main()
{
    int n,r;
    cout<<"Please enter the value of n: "<<endl;
    cin>>n;
    cout<<"Please enter the value of r: "<<endl;
    cin>>r;

    int ncr = nCr(n,r);
    cout<<"nCr is "<<ncr;
    return 0;
}