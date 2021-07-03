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

int main() {
    long long int n, m=0, x=-1, y;
    
    cin >> n;
    while(n--) {
        cin >> y;
        if(x!=-1 && x>y) 
            m += (x-y);
        else
            x = y;
    }
    
    cout << m << endl;
	return 0;
}