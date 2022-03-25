#include<bits/stdc++.h>
using namespace std;

#define Tanish "Tanish Solanki 0827CS191244";


int factorial(int n){
    
    //base case:
    if(n==0)
        return 1;

    return n * factorial(n-1);
}
int main()
{
    cout << Tanish;
    cout<< endl;

    int n;
    cin>>n;

    int ans = factorial(n);
    cout<<ans<<endl;
    return 0;
}