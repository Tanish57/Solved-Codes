#include<bits/stdc++.h>
using namespace std;

int main()
{
    // pointer to int is created, and pointing to some garbage address
    // int *p;    // BAD practice, Never do this

    // cout<<*p<<endl;

    // so instead of doing this, when we do not know what value to initalize a pointer with we can initialize it to NULL
    // such pointers are called NULL pointers

    int *p = 0;
    cout<<*p<<endl;
    return 0;
}