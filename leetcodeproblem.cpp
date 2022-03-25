// link to leetcode problem: https://leetcode.com/problems/subtract-the-product-and-sum-of-digits-of-an-integer/https://leetcode.com/problems/subtract-the-product-and-sum-of-digits-of-an-integer/

#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin>>n;

    int sum = 0;
    int product = 1;
    while(n!=0){
        int temp = n%10;
        sum += temp;
        product *= temp;
        n = n/10;
    }
    int result = product - sum;
    cout<< result;
    return 0;
}