#include<bits/stdc++.h>
using namespace std;


int power(int n){

    //base case
    if(n==0)
        return 1;

    // recursive relation
    return  2 * power(n-1);
}
int main()
{
    cout<<"Tanish Solanki 0827CS191244"<<endl;

    int n;
    cin>>n;
    
    int ans = power(n);
    cout<<ans;
    return 0;
}