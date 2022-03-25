#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin>>n;

    bool power = false;
    for(int i = 0;i<=30;i++){
        int ans = pow(2,i);

        if(ans == n){
            power = true;
            break;
        }
    }

    if(power){
        cout<<"True";
    }
    else{
        cout<<"False";
    }
    return 0;
}

#include<bits/stdc++.h>
using namespace std;

int main()
{
    char ch = '1';
    switch (ch)
    {
    case 1: cout<<"First"<<endl;
        break;

    case '1': cout<<"Character '1' "<<endl;
        break;
    
    default:cout<<"defualt case"<<endl;
        break;
    }
    return 0;
}