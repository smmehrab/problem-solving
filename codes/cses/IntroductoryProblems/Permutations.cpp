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
    int n, m;
    cin >> n;
    if(n==2 || n==3)
        cout << "NO SOLUTION" << endl;
    else if(n==1)
        cout << n << endl;
    else {
        int j = (n==4) ? 2 : 1;
        for(int i=0; i<n; i++, j+=2) {
            if(j>n)
                j = (n&1) ? j%n : (n==4 ? (j-1)%n : (j+1)%n);
            cout << j << " ";
        }
    }
	return 0;
}