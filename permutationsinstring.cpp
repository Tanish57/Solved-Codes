#include<bits/stdc++.h>
using namespace std;

void solve(string str, vector<string>& ans, int index){
    //base case
    if(index >= str.size()){
        ans.push_back(str);
        return;
    }   

    for(int i = index; i<str.size(); i++){
        swap(str[index], str[i]);
        solve(str, ans, index+1);
        //backtracking:
        swap(str[index], str[i]);
    }
}

vector<string> generatePermutations(string &str){
    vector<string> ans;
    int index = 0;
    solve(str, ans, index);
    return ans;
}

int main()
{
    string str = "abc";
    vector<string> ans = generatePermutations(str);
    
    for(int i = 0; i<ans.size(); i++){
        cout<<ans[i]<<endl;
    }
    return 0;
}