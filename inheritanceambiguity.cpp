#include<bits/stdc++.h>
using namespace std;

class A{
    public:
    void func1(){
        cout<<"class A func1"<<endl;
    }
};
class B{
    public:
    void func1(){
        cout<<"class B func1"<<endl;
    }
};

class C : public A, public B{

};

int main()
{
    C obj;
    obj.A::func1();  
    obj.B::func1();  
    return 0;
}