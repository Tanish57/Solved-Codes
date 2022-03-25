#include<bits/stdc++.h>
using namespace std;

void print(int n){
    // base case:
    if(n == 0)
        return;
    
    print(n-1); //head recursion 
    cout<<n<<" ";
}

int main()
{   
    cout<<"Tanish Solanki 0827CS191244"<<endl;
    int n;
    cin>>n;

    print(n);
    return 0;
}
