#include<bits/stdc++.h>
using namespace std;

class Animal{

    public:
    int age;
    int weight;

    public:
    void speak(){
        cout<<"Speaking "<<endl;
    }
};

class Dog:public Animal{

};

class GermanShephard: public Dog{

};
int main()
{
    GermanShephard g;
    g.speak();
    cout<<g.age<<endl;  
    return 0;
}