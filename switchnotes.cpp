#include<bits/stdc++.h>
using namespace std;

int main()
{
    int amt ;
    cin>>amt;

    int one=0, twenty=0, fifty=0, hundred=0;

    switch(1){
        case 1:
        hundred = hundred + amt/100;
        cout<<"100 Rs. notes: "<<hundred<<endl;
        amt %= 100;

        case 2:
        fifty += amt/50;
        cout<<"50 Rs. notes: "<<fifty<<endl;
        amt %= 50;

        case 3:
        twenty += amt/20;
        cout<<"20 Rs. notes: "<<twenty<<endl;
        amt %= 20;

        case 4:
        one += amt/1;
        cout<<"1 Rs. notes: "<<one<<endl;
        break;

        default:
        cout<<"This is default case";
    }
    return 0;
}