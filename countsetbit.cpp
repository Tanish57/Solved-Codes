#include<bits/stdc++.h>
using namespace std;

int countBit(int n){
    int count = 0;
    while(n!=0){
        int bit = n&1;
        if(bit == 1){
            count+=1;
        }
        n = n >> 1;
    }
    return count;
}

int main()
{
    int a,b;
    cin>>a>>b;
    int total = countBit(a) + countBit(b);
    cout<<total;
    return 0;
}