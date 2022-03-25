#include<bits/stdc++.h>
using namespace std;

void update(int** p2){
    // p2 = p2+1;
    // kuch change hoga?    -- no changes

    // *p2 = *p2+1;
    //kuch change hoga? -- yes, value of p changed and address updated by 4 memory locations(cause int)

    **p2 = **p2 + 1;
    // kuch change hoga?? -- yes, value of **p2 -> value of *p -> value of i updated by +1, so i+1; 
}

int main()
{
    int i = 5;
    int* p = &i;
    int** p2 = &p;

    cout << endl << endl << "Working fine" << endl;

    cout << endl ;

    cout << "before " << i << endl;
    cout << "before " << p << endl;
    cout << "before " << p2 << endl;
    update(p2);
    cout << "after " << i << endl;
    cout << "after " << p << endl;
    cout << "after " << p2 << endl;
    cout << endl << endl;
    
    return 0;
}