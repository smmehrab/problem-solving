/*
************************************************
username    :   smmehrab
fullname    :   s.m.mehrabul islam
email       :   mehrab.24csedu.001@gmail.com
institute   :   university of dhaka, bangladesh
session     :   2017-2018
************************************************
*/
#include<bits/stdc++.h>
using namespace std;

int main(){
    int n,i,j,k;
    stack<char> s;
    vector<char> v;
    char t;

    cin >> n;
    for(i=0, j=1;i<n;i++){
        cin >> t;
        if(t == '(') s.push(t);
        else if(t == ')'){
            if(s.size()!=1 && s.top()=='('){

            }
            else{

            }
        }
    }

    return 0;
}

