#include<iostream>
using namespace std;

int main()
{
    // #ifndef ONLINE_JUDGE
    //     freopen("input.txt","r",stdin);
    //     freopen("output.txt","w",stdout);
    // #endif

    int sidea, sideb, sidec;
    cout<<"Please enter the three sides of a triange to find out whether it is a scalene, isosceles or equilateral triangle"<<endl;
    cin>>sidea>>sideb>>sidec;

    if(sidea==sideb && sideb==sidec){
        cout<<"This is an equilateral Triangle";
    }
    else if(sidea == sideb || sidea == sidec || sideb == sidec){
        cout<<"This is an isosceles triangle";
    }
    else{
        cout<<"This is an scalene triangle";
    }
    return 0;
}