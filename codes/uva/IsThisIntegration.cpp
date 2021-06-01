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
    double r, a, b, c;
    double pi = 2 * acos(0.0); 
    cout << fixed;
    cout << setprecision(3);
    while(cin>>r){
        a = (r*r)*(1-(pi/6)-(sqrt(3)/4));
        b = (r*r)*((pi/12)-1+(sqrt(3)/2));
        c = (r*r)*(1+(pi/3)-sqrt(3)); 
        cout << c << " " << (4*b) << " " << (4*a) << endl;
    }
    return 0;
}