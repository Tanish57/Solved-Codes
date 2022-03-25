// link to problem : https://leetcode.com/problems/number-of-1-bits/

#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin>>n;

    int count = 0;
    while(n!=0){

        // checking last bit
        if(n&1){
            count++;
        }
        n = n>>1;
    }
    cout<<count;
    return 0;
}