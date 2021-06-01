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
    long long int a[200100], ans;
    cin >> t;
    while(t--){
        cin >> n;
        ans = 0;
        for(int i=0; i<n; i++){
            cin >> a[i];
            if(i!=0 && a[i]<a[i-1]) ans += a[i-1]-a[i];
        } 
        cout << ans << endl;
    }
    return 0;
}