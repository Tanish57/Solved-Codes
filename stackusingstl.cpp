#include<bits/stdc++.h>
using namespace std;

int main()
{
    // creation of a stack
    stack<int> s;

    //push operation
    s.push(2);
    s.push(3);

    //pop operation
    s.pop();

    //peek operation
    cout << "Printing top element " << s.top() << endl;

    //is empty operation:
    if(s.empty()){
        cout<<"Stack is empty!"<<endl;
    }
    else{
        cout<<"Stack is not empty"<<endl;
    }

    cout<<s.size()<<endl;

    return 0;
}