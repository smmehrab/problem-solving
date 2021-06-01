/*
************************************************
username    :   smmehrab
fullname    :   s.m.mehrabul islam
email       :   mehrab.24csedu.001@gmail.com
institute   :   university of dhaka, bangladesh
session     :   2017-2018
************************************************
*/
#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n,o=0,c=0,i,j=0,k,r = 1;
    char s[300011];

    cin >> n;
    cin >> s;

    if(n&1) r=0;

    else{
        for(i=0;i<n;i++){
            if(s[i]=='(') o++;
            else if(s[i]==')') c++;
        }

        o=(n/2)-o;
        c=(n/2)-c;

        if(o<0||c<0) r=0;

        else{
            for(i=0;i<n;i++){
                if(s[i]=='(')
                    j++;
                else if(s[i]==')')
                    j--;
                else if(o>0){
                    s[i]='(';
                    o--;
                    j++;
                }
                else{
                    s[i]=')';
                    c--;
                    j--;
                }

                if(i!=n-1 && j<=0) r=0;
            }
        }
    }

    if(r) cout << s << endl;
    else cout << ":(" << endl;


    return 0;
}
