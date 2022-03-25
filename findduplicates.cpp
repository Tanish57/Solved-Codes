#include<bits/stdc++.h>
using namespace std;

int findDuplicate(vector<int> &arr) 
{
    
	int ans = 0;
    
    // XORing all array elements
    for(int i = 0; i<arr.size();i++){
        ans = ans^arr[i];
        cout<<ans<<endl;
    }
    cout<<ans<<endl;
    cout<<"XOR from 1 to N-1"<<endl;
    // XOR from 1 to N-1
    for(int i = 1; i<arr.size();i++){
        ans = ans^i;
        cout<<ans<<endl;
    }
    cout<<ans<<endl;
    return ans;
}

int main(){

    vector<int> arr = {5,1,2,3,4,2};

    cout<<findDuplicate(arr);
    return 0;
}