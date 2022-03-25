#include<iostream>
using namespace std;

int main()
{
    char c;
    int isLowerCaseVowel, isUpperCaseVowel;
    cout<<"Enter an alphabet: ";
    cin>>c;

    isLowerCaseVowel = (c=='a' || c=='e' || c=='i' || c=='o' || c=='u');
    
    isUpperCaseVowel = (c=='A' || c=='E' || c=='I' || c=='O' || c=='U');

    if(isLowerCaseVowel || isUpperCaseVowel){
        cout<<c<<" is a vowel";
    }
    else{
        cout<<c<<" is a consonant";
    }
    return 0;
}