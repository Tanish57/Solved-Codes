#include<bits/stdc++.h>
using namespace std;

class Animal{

    public:
    int age;
    int weight;

    public:
    void bark(){
        cout<<"Barking "<<endl;
    }
};

class Human{
    public:
    string color;

    void speak(){
        cout<<"Speaking"<<endl;
    }
};

// multiple inheritance
class Hybrid: public Animal, public Human{

};
int main()
{
    Hybrid h;
    h.speak();
    h.bark();
    return 0;
}