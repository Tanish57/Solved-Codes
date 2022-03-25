#include<bits/stdc++.h>
using namespace std;

void moveZeroes(vector<int>& nums) {
        int i = 0;
        
        for(int j = 0; j<nums.size(); j++){
            if(nums[j] != 0){
                swap(nums[j], nums[i]);
                i++;
            }
        }
}

void print(vector<int> arr){
    for(int i = 0; i<arr.size(); i++){
        cout<<arr[i]<<" ";
    }cout<<endl;
}
int main()
{
    vector<int> nums = {0, 1, 0, 3, 12};
    moveZeroes(nums);
    print(nums);
    return 0;
}