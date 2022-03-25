#include<bits/stdc++.h>
using namespace std;

int main()
{
    int a,b, output;
    char op;
    cout<<"Please enter the value of a: ";
    cin>>a;
    cout<<"Please enter the value of b: ";
    cin>>b;
    cout<<"Please enter the operator (+,-,*,/,%): ";
    cin>>op;

    switch(op){
        case '+': output = a + b;
                cout<<output<<endl;
                break;
        case '-': output = a - b;
                cout<<output<<endl;
                break;
        case '*': output = a * b;
                cout<<output<<endl;
                break;
        case '/': output = a / b;
                cout<<output<<endl;
                break;
        case '%': output = a % b;
                cout<<output<<endl;
                break;
        default:cout<<"invalid operator"<<endl;
    }
    return 0;
}