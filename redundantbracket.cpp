#include<bits/stdc++.h>
using namespace std;

bool findRedundantBrackets(string &s)
{
    stack<char> st;
    
    for(int i = 0; i<s.length(); i++){
        char ch = s[i];
        
        if(ch == '(' || ch == '+' || ch == '-' || ch == '*' || ch == '/' ){
            st.push(ch);
        }
        else{
            // ch ya to closing bracket hai ya to koi lowercase letter hai
            
            if(ch == ')'){
                // check if there is a operator in between opening and closing brackets
                bool isRedundant = true;
                while(st.top() != '(' ){
                    char top = st.top();
                    if(top == '+' || top == '-' || top == '*' || top == '/'){
                        isRedundant = false;
                    }
                    st.pop();
                }
                if(isRedundant == true){
                    return true;
                }
                st.pop();
            }
        }
    }
    return false;
}

int main()
{
    
    return 0;
}