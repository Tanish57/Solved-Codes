#include<bits/stdc++.h>
using namespace std;

// function to print array;
void printArray(int arr[], int size){
    for(int i =0; i<size ;i++ ){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}

int main()
{
    int array[15];
    
    for(int i = 0; i<=14;i++){
        cout<<array[i]<<endl;
    }

    // initializing an array
    int second[3] = {3,5,7};

    cout<<"Second Array: "<<endl;

    // Accessing an element:
    cout<<"The second element is : ";
    cout<<second[1]<<endl;

    // printing the complete array: 
    for(int i = 0; i<=2;i++){
        cout<<second[i]<<endl;
    }

    int n = 15;
    int third[n] = {2, 7};
    cout<<"third array:"<<endl;
    for(int i = 0; i<n;i++){
        cout<<third[i]<<" ";
    }
    cout<<endl;
    // initializing all locations with 0:
    n = 10;
    int fourth[n] = {0};
    cout<<"fourth array:"<<endl;
    printArray(fourth, n);
    
    // int fifth[] = { [0 ... 9] = 1};
    int fifth[10];
    fill_n(fifth,10,1); //to initialize all 10 values with 1
    cout<<"fifth array:"<<endl;
    printArray(fifth, 10);

    char ch[5] = {'a', 'b', 'c' , 'r', 'p'};
    cout<<"character array ch:"<<endl;
    for(int i=0;i<5;i++){
        cout<<ch[i]<<" ";
    }cout<<endl;

    double firstdouble[5];
    float firstfloat[6];
    bool firstbool[9];
    return 0;
}