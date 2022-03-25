#include<bits/stdc++.h>
using namespace std;

void rotate(vector<vector<int>>& matrix) {
    int row = matrix.size();
    int col = matrix[0].size();
        
    for(int i = 0; i<row;i++){
        for(int j = i; j<col; j++){
            swap(matrix[i][j], matrix[j][i]);
        }
        reverse(matrix[i].begin(), matrix[i].end());
    }
}

int main()
{
    vector<vector<int>> matrix = {{1,2,3},{4,5,6},{7,8,9}};
    cout<<"array/matrix: "<<endl;
    
    for(int i = 0; i<matrix.size(); i++){
        for(int j = 0; j<matrix[0].size(); j++){
            cout<<matrix[i][j]<<" ";
        }cout<<endl;
    }

    rotate(matrix);
    cout<<endl;
    cout<<"Rotated Matrix is : "<<endl;
    for(int i = 0; i<matrix.size(); i++){
        for(int j = 0; j<matrix[0].size(); j++){
            cout<<matrix[i][j]<<" ";
        }cout<<endl;
    }
    return 0;
}