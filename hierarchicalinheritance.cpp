#include<bits/stdc++.h>
using namespace std;

//Hierarchical Inheritance

class A{
    public:
    void func1(){
        cout<<"inside class A function 1"<<endl;
    }
};

class B : public A{
    public:
    void func2(){
        cout<<"inside class B function 2"<<endl;
    }
};
class C : public A{
    public:
    void func3(){
        cout<<"inside class C function 3"<<endl;
    }
};

int main()
{
    cout<<"created obj1 of class A"<<endl;
    A obj1;
    obj1.func1();

    cout<<"created obj2 of class B"<<endl;
    B obj2;
    obj2.func1();
    obj2.func2();

    cout<<"created obj3 of class C"<<endl;
    C obj3;
    obj3.func1();
    obj3.func3();
    return 0;
}