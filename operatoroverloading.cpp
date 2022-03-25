#include<bits/stdc++.h>
using namespace std;

class B{
    public:
    int a;
    int b;

    public:
    int add(){
        return a+b;
    }

    void operator+ (B &obj){
        int value1 = this -> a;
        int value2 = obj.a;
        cout<<"output "<< value2 - value1 <<endl;
    }

    void operator() (){
        cout<<"Me bracket hu"<< this->a <<endl; // jab bhi bracket use ho print "me bracket hu" 
                           // aur jis bhi object ne call kiya ho uski a vali value print krdena
    }
    // void operator+ (B &obj){
    //     cout<<"Hello Tanish"<<endl;
    // }
};

int main()
{
    B obj1, obj2;
    obj1.a = 4;
    obj2.a = 7;
    obj1+obj2; 
    obj1(); 
    return 0;
}