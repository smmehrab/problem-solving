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
    int t, n, k, ans;
    cin >> t;
    while(t--){
        cin >> n >> k;

        if(k>=n) ans = (k-n);
        else{
            if(n%2==0){
                ans = (k%2==0) ? 0 : 1;
            } else{
                ans = (k%2==1) ? 0 : 1;
            }
        }

        cout << ans << endl;
    }

    return 0;
}