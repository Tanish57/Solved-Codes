#include<bits/stdc++.h>
using namespace std;

string removeDuplicates(string s) {
       
        string temp="";
        temp.push_back(s[0]);
        for(int i=1;i<s.length();i++){
             if(temp.back()==s[i]){
                 temp.pop_back();
             }
            else{
             temp.push_back(s[i]);
            }
        }
        return temp;
}


int main()
{
    string s = "axxxxyyyyb" ;
    cout<<removeDuplicates(s)<<endl;
    return 0;
}