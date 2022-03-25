#include<bits/stdc++.h>
// #include "Hero.cpp"  // including Hero.cpp, containing class Hero
using namespace std;

class Hero{

    //properties:
    private:
    int health;

    public:
    char *name;
    char level;
    
    Hero(){
        cout<<"Constructor Called"<<endl;
        name = new char[100];
    }

    // parameterized constructor
    Hero(int health){
        cout<<"this -> "<<this<<endl;
        this -> health = health; 
    }

    Hero(int health, char level){
        this -> level = level;
        this -> health = health;
    }

    //user defined copy constructor
    Hero(Hero& temp){

        char* ch = new char [strlen(temp.name) + 1];
        strcpy(ch, temp.name);
        this->name = ch;

        cout<<"Copy constructor callled"<<endl;
        this->health = temp.health;
        this->level = temp.level;
    }
    // datafunction/ behavior
    void print(){
        cout<<endl;
        cout<<"Name: "<<this->name<<", ";
        cout<<"health "<< this->health<<", ";
        cout<<"level "<<this->level<<endl;
        cout<<endl;
    }

    //getter:
    int getHealth(){
        return health;
    }

    char getLevel(){
        return level;
    }

    //setter:
    void setHealth(int h){
        
        health = h;
    }

    void setLevel(char c){
        level = c;
    }

    void setName(char name[]){
        strcpy(this->name, name);
    }
};

int main()
{   
    Hero hero1;
    hero1.setHealth(12);
    hero1.setLevel('D');
    char name[7] = "Tanish";
    hero1.setName(name);

    hero1.print();

    //use default copy constructor ( comment your own copy constructor if created)
    Hero hero2(hero1);
    hero2.print();

    hero1.name[0] = 'G';
    hero1.print();

    hero2.print();

    //Hero hero2 = hero1; // this is also a way to call copy constructor

    // Hero suresh(70, 'C');
    // suresh.print();

    // Hero ritesh(suresh);
    // ritesh.print();
    //ritesh.health == suresh.health
    //ritesh.level == suresh.level

    //object created statically
    // Hero ramesh(30);    //ramesh is current object, so 'this'pointer will store the address of ramesh
    // cout<<"Address of ramesh "<< &ramesh<<endl;

    // Hero temp(22, 'B');
    // //object created dynamically
    // Hero *tanish = new Hero;

    // //static allocation ( created object a of class Hero statically)
    // Hero a;
    // a.setLevel('B');
    // a.setHealth(80);

    // cout<<"Level is "<< a.level <<endl;
    // cout<<"health is "<< a.getHealth() <<endl;
    // //dynamic allocation (creating object of a class dynamically)
    // Hero *b = new Hero;
    // b->setHealth(70);
    // b->setLevel('A');

    // cout<<"Level is "<< (*b).level <<endl;
    // cout<<"health is "<< (*b).getHealth() <<endl;

    // cout<<"Level is "<< b -> level <<endl;
    // cout<<"health is "<< b -> getHealth() <<endl;
    return 0;
}