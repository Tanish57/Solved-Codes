#include<bits/stdc++.h>
using namespace std;

class A{
    public:
    void sayHello(){
        cout<<"Hello Tanish Solanki"<<endl;
    }
    void sayHello(string name){
        cout<<"Hello "<< name <<endl;
    }
    void sayHello(char name){
        cout<<"Hello "<< name <<endl;
    }
    int sayHello(string name, int n){
        cout<<"Hello "<< name <<endl;
        return n;
    }
};

int main()
{
    A obj;
    obj.sayHello();
    obj.sayHello("Muskan");
    return 0;
}