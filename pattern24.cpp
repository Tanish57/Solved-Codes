#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin>>n;

    int i = 1;
    while(i<=n){
        // space print karlo
        int space = n-i;
        while(space){
            cout<<" ";
            space--;
        }
        // numbers print karlo
        int j = 1;
        int nums = i;
        while(j<=i){
            cout<<nums;
            j++;
        }
        cout<<endl;
        i++;
    }
    return 0;
}