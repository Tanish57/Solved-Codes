#include<bits/stdc++.h>
using namespace std;

void rotate(vector<int>& nums, int k) {
        vector<int> temp(nums.size());
        
        for(int i = 0; i < nums.size(); i++){
            temp[(i+k)%nums.size()] = nums[i];
        }
        //copy temp into nums vector
        nums = temp;
}

void print(vector<int> arr){
    for(int i =0; i<arr.size();i++){
        cout<<arr[i]<<" ";
    }cout<<endl;
}
int main()
{
    vector<int> nums = {1,2,3,4,5,6,7};
    rotate(nums, 3);
    print(nums);
    return 0;
}