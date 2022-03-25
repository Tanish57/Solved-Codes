#include<bits/stdc++.h>
using namespace std;

void reverse(string& s, int n){
    int st = 0;
    int e = n-1;

    while(st<e){
        swap(s[st++], s[e--]);
    }
}

void reverseWord(string& sentence, int n){
    reverse(sentence, sentence.length());
    int i = 0;
    while(sentence[i] != '\0'){
        int s = i;
        while(sentence[i] != ' ' && sentence[i] != '\0'){
            i++;
        }
        int e = i-1;
        while(s<e){
            swap(sentence[s++], sentence[e--]);
        }
        if(sentence[i] == ' ')
            i++;
    }
}
int main(){

    string s = "My name is tanish";
    
    // reverseWord(s, s.length());
    reverseWord(s, s.length());
    cout<<s;
}