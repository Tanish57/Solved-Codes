#include<bits/stdc++.h>
using namespace std;

int main()
{
    int arr[10] = {23, 122, 41, 67};
    cout<<"Address of first memory block is "<<arr<<endl;
    cout<<"Address of first memory block is "<< &arr[0] <<endl;
    cout<<"Value at address of arr is "<< *arr <<endl;
    cout<<"Value of *arr+1 is "<< *arr+1 <<endl;
    cout<<"Value of *(arr+1) is "<< *(arr+1) <<endl;
    cout<<"Value of *(arr)+1 is "<< *(arr)+1 <<endl;
    cout<<"Value of arr[2] is "<< arr[2] <<endl;
    cout<<"Value of *(arr+2) is "<< *(arr+2) <<endl; //value of arr[2]
    cout<<"Value of 2[arr] is "<< 2[arr] <<endl;
    cout<<"Value of *(2+arr) is "<< *(2+arr) <<endl; //value of arr[2]
    
    // first difference:
    cout<<sizeof(arr)<<endl;
    cout<<"Size of first value " <<sizeof(*arr)<<endl;
    cout<<"Size of &arr " <<sizeof(&arr)<<endl; //address of arr -> address is 8 bytes
    int* ptr = &arr[0];
    cout<<sizeof(ptr)<<endl;
    cout<<sizeof(*ptr)<<endl;   //4 will be output cause value is an integer and integer are of 4bytes
    cout<<sizeof(&ptr)<<endl;

   //2nd difference:
   int a[20] = {1,2,3,5};
   cout<< &a[0] <<endl;
   cout<< &a <<endl;    //same as above
   cout<< a << endl;    //same as above
    cout<<"pointer :"<<endl;
   int *p = &a[0];
   cout<< p << endl;    // value pointer is storing, i.e address of a[0]
   cout<< *p << endl;   // value at pointer, i.e value of a[0] -> 1
   cout<< &p << endl;   // address of pointer itself

    //3rd difference:

    int arrr[10];
    // arr = arr + 1;  gives error;
    
    int *ptrr = &arr[0];
    cout<<"Before " <<ptrr<<endl;
    ptrr = ptrr + 1;
    cout<<"After : "<<ptrr<<endl;

    return 0;
}