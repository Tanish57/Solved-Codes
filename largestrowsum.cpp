#include<bits/stdc++.h>
using namespace std;

// to print index of largest col sum : 
void largestColSum(int arr[][3], int row, int col){

    for(int i =0; i<row; i++){
        int sum = 0;
        for(int j = 0; j<col; j++){
            sum += arr[i][j];
        }
        cout<<sum<<" ";
    }cout<<endl;
}

// to print index of largest row sum:
int largestRowSum(int arr[][3], int row, int col){

    int maxi = INT_MIN;
    int rowIndex = -1;

    for(int i =0; i<row; i++){
        int sum = 0;
        for(int j = 0; j<col; j++){
            sum += arr[i][j];
        }
        
        if(sum > maxi){
            maxi = sum;
            rowIndex = i;
        }
    }
    cout<<"The maximum sum is "<<maxi<<endl;
    return rowIndex;
}

int main()
{
    int arr[3][3];

    cout<<"Enter the elements: "<<endl;
    for(int i =0; i<3; i++){
        for(int j = 0; j<3; j++){
            cin>>arr[i][j];
        }
    }

    cout<<"Output array/matrix: "<<endl;
    
    for(int i = 0; i<3; i++){
        for(int j = 0; j<3; j++){
            cout<<arr[i][j]<<" ";
        }cout<<endl;
    }

    int num = largestRowSum(arr, 3, 3);
    cout<<"The index of largest sum of row is : "<< num <<endl;
    
    // cout<<"The sum of each column is : "<<endl;
    return 0;
}