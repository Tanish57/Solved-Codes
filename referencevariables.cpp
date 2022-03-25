#include<bits/stdc++.h>
using namespace std;

void update1(int n){
    n++;
}

void update2(int& n){   //created a reference variable of n
    n++;
}

int main()
{
    int i = 5;
    // create a reference variable
    int& j = i;
    
    cout << i << endl;
    j++;
    cout << i << endl;

    cout<< endl;
    int n = 5;
    cout << "Before " << n << endl;
    update1(n);
    cout << "After " << n << endl;
    cout<< "Updating via reference variable: "<< endl;
    cout << "Before " << n << endl;
    update2(n);
    cout << "After " << n << endl;
    return 0;
}