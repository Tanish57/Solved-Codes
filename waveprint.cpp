#include<bits/stdc++.h>
using namespace std;

vector<int> wavePrint(vector<vector<int>> arr, int nRows, int mCols)
{
    //Write your code here
    vector<int> ans;
    for(int col=0; col < mCols; col++){
        if(col & 1) //signifies odd index -> bottom to top
        {
            for(int row = nRows-1; row >= 0; row--){
                ans.push_back(arr[row][col]);
            }
        }
        else // 0 or even index -> top to bottom
        {
            for(int row = 0; row< nRows; row++){
                ans.push_back(arr[row][col]);
            }
        }
    }
    return ans;
}

int main()
{
    vector<vector<int>> arr = {{1, 2, 3, 4}, {5, 6, 7, 8}, {9, 10, 11, 12}};
    vector<int> wave = wavePrint(arr, 3, 4);
    for(int i =0; i<wave.size();i++){
        cout<<wave[i]<<" ";
    }cout<<endl;
    return 0;
}