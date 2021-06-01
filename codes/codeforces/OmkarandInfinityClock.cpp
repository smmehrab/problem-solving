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
    int t, n;
    long long int a[200100],  b[200100], ans, mx, d, k;
    cin >> t;
    while(t--){
        cin >> n >> k;
        ans = 0;

        for(int i=0; i<n; i++){
            cin >> a[i];
            if(i==0) mx = a[i];
            else mx=max(mx, a[i]);
        } 

        for(int i=0; i<n; i++){
            a[i] = mx - a[i];
            if(i==0) d=a[i];
            else d=max(d, a[i]);
        }

        for(int i=0; i<n; i++)
            b[i] = d - a[i]; 

        if(k%2==0){
            for(int i=0; i<n; i++)
                cout << b[i] << " "[i==n-1];
        } else{
            for(int i=0; i<n; i++)
                cout << a[i] << " "[i==n-1];
        }
        cout << endl;
    }
    return 0;
}