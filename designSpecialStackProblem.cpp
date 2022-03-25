#include<bits/stdc++.h>
using namespace std;

#include<stack>
class SpecialStack {
    // Define the data members.
	stack<int> s;
    int mini;
    /*----------------- Public Functions of SpecialStack -----------------*/
    public:
        
    void push(int data) {
        // for first element 
        if(s.empty()){
            s.push(data);
            mini = data;
        }
        else{
            if(data < mini){
                int val = 2 * data - mini;
                s.push(val);
                mini = data;
            }
            else{
                s.push(data);
            }
        }
    }

    int pop() {
        // check underflow condition
        if(s.empty()){
            return -1;
        }
        int curr = s.top();
        s.pop();
        if(curr > mini){
            return curr;
        }
        else{
            int prevMin = mini;
            int val = 2*mini - curr;
            mini = val;
            return prevMin;
        }
    }

    int top() {
        if(s.empty()){
            return -1;
        }
        int curr = s.top();
        if(curr < mini){
            return mini;
        }
        else{
            return curr;
        }
    }

    bool isEmpty() {
        return s.empty();
    }

    int getMin() {
        if(s.empty()){
            return -1;
        }
        return mini;
    }  
};

int main()
{
    SpecialStack s;
    s.push(5);
    s.push(3);
    s.push(8);
    s.push(2);
    s.push(4);
    cout<<s.top()<<endl;
    cout<<s.getMin()<<endl;
    s.pop(); 
    cout<<s.top()<<endl;
    cout<<s.getMin()<<endl;
    s.pop();
    cout<<s.top()<<endl;
    cout<<s.getMin()<<endl;

    return 0;
}