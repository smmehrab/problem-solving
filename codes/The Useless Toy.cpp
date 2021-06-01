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

int getVal(char c){
    if(c == 118)
        return 0;
    else if(c == 60)
        return 1;
    else if(c == 94)
        return 2;
    else if(c == 62)
        return 3;
}

int main()
{
    int n;
    char a,b;

    cin >> a >> b;
    cin >> n;

    if (!(n%2)) cout << "undefined" << endl;
    else{
        n%=4;
        if((getVal(a)+n)%4==getVal(b)) cout << "cw" << endl;
        else cout << "ccw" << endl;
    }

    return 0;
}
