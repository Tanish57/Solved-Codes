#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin>>n;

    int i = 1;
    while(i<=n){
        // space print karlo
        int space = i-1;
        while(space){
            cout<<" ";
            space--;
        }
        // stars print karlo
        int j = 1;
        int stars = n-i+1;
        while(j<=stars){
            cout<<"*";
            j++;
        }
        cout<<endl;
        i++;
    }
    return 0;
}