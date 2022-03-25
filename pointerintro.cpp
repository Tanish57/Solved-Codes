#include<bits/stdc++.h>
using namespace std;

int main()
{
    int num = 5;

    cout<<num<<endl;

    // address of operator - &
    cout<< "Address of num is " << &num << endl;

    int *ptr = &num;    // pointer created

    cout<<"Address is : "<< ptr << endl;
    cout<<"value is : "<< *ptr << endl; 


    double d = 4.2;
    double *p2 = &d;

    cout<<"Address is : "<< p2 << endl;
    cout<<"value is : "<< *p2 << endl; 

    cout<<"size of ptr is: " << sizeof(ptr)<<endl;
    cout<<"size of value at ptr is: " << sizeof(*ptr)<<endl;
    cout<<"size of p2 is: "<< sizeof(p2)<<endl;
    cout<<"size of value at p2 is: "<< sizeof(*p2)<<endl;

    return 0;
}