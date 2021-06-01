/*
************************************************
username    :   smmehrab
fullname    :   s.m.mehrabul islam
email       :   mehrab.24csedu.001@gmail.com
institute   :   university of dhaka, bangladesh
session     :   2017-2018
************************************************
*/
#include<iostream>
#include<bits/stdc++.h>
#include<algorithm>

using namespace std;

int main(){

    int q,a,b,c;
    cin >> q;
    for(int i=0;i<q;i++){
        cin >> a >> b >> c;

        if(abs(a-c)<abs(b-c))
            cout << "Cat A" << endl;
        else if(abs(a-c)>abs(b-c))
            cout << "Cat B" << endl;
        else
            cout << "Mouse C" << endl;
    }

    return 0;
}
