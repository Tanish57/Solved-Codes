#include<bits/stdc++.h>
using namespace std;

class TwoStack {
	int *arr;
    int top1;
    int top2;
    int size;
public:

    // Initialize TwoStack.
    TwoStack(int s) {
        this -> size = s;
        top1 = -1;
        top2 = s;
        arr = new int[s];
    }
    
    // Push in stack 1.
    void push1(int num) {
        //there is atleast 1 empty space present
        if(top2 - top1 > 1){
            top1++;
            arr[top1] = num;
        }
        
    }

    // Push in stack 2.
    void push2(int num) {
        //there is atleast 1 empty space present
        if(top2 - top1 > 1){
            top2--;
            arr[top2] = num;
        }
        
    }

    // Pop from stack 1 and return popped element.
    int pop1() {
        if(top1 >= 0){
            int ans = arr[top1];
            top1--;
            return ans;
        }
        else{
            return -1;
        }
    }

    // Pop from stack 2 and return popped element.
    int pop2() {
        if(top2 < size){
            int ans = arr[top2];
            top2++;
            return ans;
        }
        else{
            return -1;
        }
    }
    
     int peek1(){
        if(top1 >= 0){
            return arr[top1];
        }
        else{
            cout<<"Stack is Empty"<<endl;
            return -1;
        }        
    }

    int peek2(){
        if(top2 < size){
            return arr[top2];
        }
        else{
            cout<<"Stack is Empty"<<endl;
            return -1;
        }        
    }
};


int main()
{
    TwoStack st(6);

    st.push1(2);
    st.push2(3);

    cout<<st.peek1()<<endl;
    cout<<st.peek2()<<endl;
    st.push1(4);
    cout<<st.peek1()<<endl;
    st.push2(5);
    cout<<st.peek2()<<endl;
    return 0;
}