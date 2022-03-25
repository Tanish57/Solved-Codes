#include<bits/stdc++.h>
using namespace std;

int modularExponentiation(int x, int n, int m) {

    int res = 1;
    
    while(n>0){
        if(n&1) //odd 
        {
         res = (1LL*(res) * (x)%m)%m;   
        }
        x = (1LL*(x)%m *(x)%m)%m;
        n = n>>1;	//basically dividing b by 2 at low expense using bitwise operator
    }
    return res;    
}

int main()
{
    
    return 0;
}