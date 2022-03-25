#include<bits/stdc++.h>
using namespace std;

int main()
{
    int i = 5;
    int* p = &i;
    int** p2 = &p;

    cout << endl << endl << "Working fine" << endl;

    cout << "Address of p is " << &p << endl;
    cout << "printing **p2: " << **p2 << endl;

    cout << "Printing value of i directly: " << i << endl;
    cout << "Printing value of i using *p: " << *p << endl;
    cout << "Printing value of i using **p2: " << **p2 << endl;

    cout << endl << endl;

    cout << "Address of i is " << &i << endl;
    cout << "Printing p " << p << endl;
    cout << "Value of p2 ( printing *p2) " << *p2 << endl;

    cout << endl << endl;

    cout << "Address of p (&p) " << &p << endl;
    cout << "Printing p2 " << p2 << endl;
    return 0;
}