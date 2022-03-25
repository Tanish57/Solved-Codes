#include<bits/stdc++.h>
using namespace std;

void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int i = m-1, j = n-1, k = m + n -1;

    while(i>=0 && j>=0){
        if(nums1[i] > nums2[j]){
            nums1[k--] = nums1[i--];
        }
        else{
            nums1[k--] = nums2[j--];
        }
    }
    // copy first array's remaining elements
    while(i>=0){
        nums1[k--] = nums1[i--];
    }
    // copy second array's remaining elements
    while(j>=0){
        nums1[k--] = nums2[j--];
    }
}

void print(vector<int>& arr){
    for(int i = 0; i < arr.size(); i++){
        cout<<arr[i]<<" ";
    }cout<<endl;
}

int main()
{
    vector<int> nums1 = {1,2,3,0,0,0};    
    vector<int> nums2 = {2,5,6};
    merge(nums1, 3, nums2, 3 );
    print(nums1);    
    return 0;
}