#include<bits/stdc++.h>
using namespace std;

void reverse(char name[], int n){
    int s = 0;
    int e = n-1;

    while(s<e){
        swap(name[s++], name[e--]);
    }
}

int getLength(char name[]){
    int count = 0;
    for(int i =0; name[i] != '\0'; i++){
        count++;
    }
    return count;
}

int main()
{
    char name[20];
    cout<<"Enter your name: "<<endl;
    cin>>name;

    cout<<"Your name is "<<name<<endl;

    cout<<"The Length of your name is "<<getLength(name)<<endl;

    cout<<"After reversing:"<<endl;
    reverse(name, getLength(name));
    cout<<"Your name is "<<name<<endl;
    return 0;
}