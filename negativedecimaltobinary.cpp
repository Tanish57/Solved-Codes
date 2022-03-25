#include<bits/stdc++.h>
using namespace std;

int main()
{
    int dec;
    cin>>dec;

    unsigned int i = 1, bit;    //here i=1 will be repesented as 000000000000000000001
    int count = 31;
    i = i<<count; // after left shifting i 31 times it becomes 10000000000000000000

    // once we get the negative deciml number as input it is already stored in binary as a signed int

    while(i!=0){
        // here we will use i as a mask to get the leftmost bit in bit variable using bit;
        bit = dec&i;
        // now as we get the leftmost bit as 1 or 0, it will be stored as 100000000000000000000
        // but we only need the leftmost bit whose value equals 1
        // so we right shift th bit variable upto count times so that it becomes 000000000000000001
        cout<<(bit>>count);
        // now as we print the leftmost bit  we need the next leftmost bit
        // for that our must be 010000000000000000000. Hence we rightshift once.
        i=i>>1;
        // the importance of count is to rightshift bit variable upto that many times to get the leftmost bit
        // and as we traverse the next leftmost bit, the amount of right shifts decreases. Hence count is decreased 
        count--;  
    }
    
    return 0;
}