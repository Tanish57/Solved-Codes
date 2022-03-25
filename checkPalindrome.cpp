#include<bits/stdc++.h>
using namespace std;

bool valid(char ch){
        if((ch>='a' && ch<='z') || (ch>='A' && ch<='Z') || (ch>='0' && ch<='9')){
            return true;
        }
        return false;
    }
char toLowercase(char ch){

    if((ch>='a' && ch<='z') || (ch>='0' && ch<='9')){
        return ch;
    }

    else{
        char temp = ch - 'A' + 'a';
        return temp;
    }
}
bool checkPalindrome(string a){

    int s = 0;
    int e = a.length()-1;

    while(s<=e){
        if(a[s] != a[e]){
            return 0;
        }
        else{
            s++;
            e--;
        }
    }
    return 1;
}

bool isPalindrome(string s) {
        //faltu character hatado
        
        string temp = "";
        
        for(int j=0; j<s.length();j++){
            if(valid(s[j])){
                temp.push_back(s[j]);
            }
        }
        
        // convert to lowercase
        for(int j=0;j<temp.length();j++){
            temp[j] = toLowercase(temp[j]);
        }
        
        //check palindrome
        return checkPalindrome(temp);
 }

int getLength(char name[]){
    int count = 0;
    for(int i =0; name[i] != '\0'; i++){
        count++;
    }
    return count;
}

int main()
{
    char name[20];
    cout<<"Enter your name: "<<endl;
    cin>>name;

    cout<<"Your name is "<<name<<endl;
    int len = getLength(name);
    cout<<"Palindrome or not: "<<checkPalindrome(name)<<endl;

    cout<<"CHARACTER is "<<toLowercase('b')<<endl;
    cout<<"CHARACTER is "<<toLowercase('A')<<endl;
    return 0;
}