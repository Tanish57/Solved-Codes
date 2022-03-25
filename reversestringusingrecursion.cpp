#include<bits/stdc++.h>
using namespace std;

void reverse(string& str, int i, int j){

    //base case:
    if(i>j)
        return;
    
    swap(str[i], str[j]);
    i++; j--;
    reverse(str, i, j);
}

int main()
{
    cout<<"Tanish Solanki 0287CS191244"<<endl<<endl;
    
    string name = "tanish";
    cout<<name<<endl;
    reverse(name, 0, name.length()-1);
    cout<<name<<endl;
    return 0;
}

//more optimized code:

// #include<bits/stdc++.h>
// using namespace std;

// void reverse(string& str, int i){

//     //base case:
//     if(i>(str.length()-i-1))
//         return;
    
//     swap(str[i], str[str.length()-i-1]);
//     i++; str.length()-i-1;
//     reverse(str, i);
// }

// int main()
// {
//     cout<<"Tanish Solanki 0287CS191244"<<endl<<endl;
    
//     string name = "tanish";
//     cout<<name<<endl;
//     reverse(name, 0);
//     cout<<name<<endl;
//     return 0;
// }