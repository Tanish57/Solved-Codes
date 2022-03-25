#include<bits/stdc++.h>
using namespace std;

void print(int *p){

    cout << p << endl;
    cout << *p << endl;
}

void update(int *p){

    // p = p + 1;
    // cout<<"inside p "<< p <<endl;

    *p = *p+1;
}

int getSum(int *arr, int n){
    
    cout<<endl <<"Size : " << sizeof(arr)<<endl;

    int sum = 0;
    for(int i = 0; i < n; i++){
        sum += arr[i];
    }

    return sum;
}

int main()
{
    int value = 5;
    int *p = &value;
    
    print(p);

    cout<<"p Before " << p << endl;
    cout<<"value of p before update "<<*p<<endl;
    update(p); 
    cout<<"p After " << p << endl; 
    cout<<"value of p after update "<<*p<<endl;


    int arr[6] = {1,2,3,4,5,8};

    cout <<"Sum is " << getSum(arr, 6)<<endl;
    cout <<"Sum is " << getSum(arr+3, 3)<<endl;
    return 0;
}