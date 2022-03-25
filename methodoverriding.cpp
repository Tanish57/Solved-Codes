#include<bits/stdc++.h>
using namespace std;

class Animal{
    public:
    void speak(){
        cout<<"Speaking"<<endl;
    }
};

class Dog : public Animal{
    public:
    void speak(){
        cout<<"barking "<<endl;
    }
};

int main()
{
    Animal a;
    a.speak();
    Dog d;
    d.speak();
    return 0;
}