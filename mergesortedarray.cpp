#include<bits/stdc++.h>
using namespace std;

void merge(int arr1[], int n, int arr2[], int m, int arr3[]){
    int i = 0, j = 0, k = 0;

    while(i<n && j<m){
        if(arr1[i] < arr2[j]){
            arr3[k++] = arr1[i++];
        }
        else{
            arr3[k++] = arr2[j++];
        }
    }
    // copy first array's remaining elements
    while(i<n){
        arr3[k++] = arr1[i++];
    }
    // copy second array's remaining elements
    while(j<m){
        arr3[k++] = arr2[j++];
    }
}

void print(int arr[], int size){
    for(int i=0; i < size; i++){
        cout<<arr[i]<<" ";
    }cout<<endl;
}

int main()
{
    int arr1[5] = {1,3,5,7,9};
    int arr2[3] = {2,4,6};
    int arr3[8] = {0};

    merge(arr1, 5, arr2, 3, arr3);

    print(arr3, 8 );
    return 0;
}

void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int a = m - 1;
        int b = n - 1;
        int c = m + n - 1;
        
        while (a >= 0 && b >= 0) {
            if (nums1[a] > nums2[b])
                nums1[c--] = nums1[a--];
            else
                nums1[c--] = nums2[b--];
        }
        
        while (a >= 0)
            nums1[c--] = nums1[a--];
        
        while (b >= 0)
            nums1[c--] = nums2[b--];
    }