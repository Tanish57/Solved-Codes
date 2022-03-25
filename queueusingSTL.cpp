#include<bits/stdc++.h>
using namespace std;

int main()
{   
    //create a queue of integer type:
    queue<int> q;

    q.push(11);
    cout<<q.front()<<endl;
    q.push(15);
    cout<<q.back()<<endl;
    q.push(13);
    cout<<q.back()<<endl;

    cout<<"Size of queue is "<<q.size()<<endl;
    
    q.pop();
    cout<<q.front()<<endl;
    if(q.empty()){
        cout<<"Queue is empty"<<endl;
    }
    else{
        cout<<"Queue is not empty"<<endl;
    }
    return 0;
}