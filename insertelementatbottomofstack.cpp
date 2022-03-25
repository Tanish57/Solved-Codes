#include<bits/stdc++.h>
using namespace std;

void solve(stack<int>& s, int x){
    if(s.empty()){
        s.push(x);
        return ;
    }
    
    int num = s.top();
    s.pop();
    
    //recursive call:
    solve(s,x);
    
    s.push(num);
    
}

stack<int> pushAtBottom(stack<int>& myStack, int x) 
{
    // Write your code here.
    solve(myStack, x);
    return myStack;
}


int main()
{
    stack<int> s;

    s.push(9);
    s.push(4);
    s.push(3);
    s.push(2);
    s.push(1);

    pushAtBottom(s, 10);

    while(!s.empty()){
        cout<<s.top()<<endl;
        s.pop();
    }
    return 0;
}