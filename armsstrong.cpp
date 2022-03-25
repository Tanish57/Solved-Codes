#include<bits/stdc++.h>
using namespace std;

int main()
{
    int num, originalnum, remainder, n=0, result = 0, power;
    cout<<"Enter an integer"<<endl;
    cin>>num;

    originalnum = num;

    while(originalnum != 0){
        originalnum /=10;
        n++;
    } 
    originalnum = num;

    while(originalnum != 0){
        remainder = originalnum % 10;
        power = round(pow(remainder, n));
        result += power;
        originalnum /= 10;
    }

    if(result==num){
        cout<<"Armstrong number"<<endl;
    }
    else{
        cout<<"not armstrong number"<<endl;
    }
    return 0;
}