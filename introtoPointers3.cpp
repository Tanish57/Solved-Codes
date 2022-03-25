#include<bits/stdc++.h>
using namespace std;

int main()
{
    int i = 5;
    int *k = &i;

    cout<<k<<endl;
    cout<<*k<<endl;

    int *p = 0;
    p = &i; // pointing a null initialized pointer to address of i;

    cout<<p<<endl;
    cout<<*p<<endl;

    cout<<endl;

    int num = 5;
    int a = num;
    cout<< "num before: "<<num<<endl;
    a++;
    cout<<"num After: " <<num<<endl;
    
    cout<<endl;

    int *ptr = &num;
    cout<< "before: "<<num<<endl;
    (*ptr)++;
    cout<<"After: " <<num<<endl;
    
    cout<<"Copying a pointer: "<<endl;
    // copying a pointer:
    int *q = ptr;
    cout<< ptr<< " - " << q <<endl;
    cout<< *ptr<< " - " << *q <<endl;

    // important concept - pointer arithmetic:
    int n = 3;
    int *t = &n;    // i is 5
    cout<< ++(*t) <<endl;
    *t = *t + 1;
    cout<< (*t) <<endl;
    cout<<"Before t: "<< t << endl;
    cout<<"Before *t: "<< *t << endl;
    t = t + 1;
    cout<<"After t: "<< t << endl;
    cout<<"After *t: "<< *t << endl;

    return 0;
}