#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin>>n;

    //creating a 2d array using dyanmic memory allocation

    int** arr = new int*[n];

    for(int i = 0; i<n; i++){
        arr[i] = new int[n];
    }
    //creation of 2d array done

    //taking input
    for(int i = 0; i<n; i++){
        for(int j = 0; j<n; j++){
            cin >> arr[i][j]; 
        }
    }
    cout<<endl;
    //printing output
    for(int i = 0; i<n; i++){
        for(int j = 0; j<n; j++){
            cout<< arr[i][j] <<" "; 
        }cout<<endl;
    }

    //creating a 2d array with different number of rows and columns:
    int row, col;
    cin >> row >> col;
    int** arr1 = new int*[row];

    for(int i=0; i<row; i++){
        arr1[i] = new int[col];
    }

    //taking input
    for(int i = 0; i<row; i++){
        for(int j = 0; j<col; j++){
            cin >> arr1[i][j]; 
        }
    }
    cout<<endl;
    //printing output
    for(int i = 0; i<row; i++){
        for(int j = 0; j<col; j++){
            cout<< arr1[i][j] <<" "; 
        }cout<<endl;
    }

    //releasing memory:
    for(int i=0; i<row; i++){
        delete [] arr[i];
    }
    delete []arr;

    for(int i=0; i<row; i++){
        delete [] arr1[i];
    }
    delete []arr1;

    return 0;
}