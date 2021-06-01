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
#include <stdio.h>
#include <math.h>
#include <stdbool.h>
using namespace std;

int main()
{
    int n, a[200], ans=0;
    cin >> n;
    for(int input=1; input<=n; input++){
        cin >> a[input];
        if(a[input]%2!=0 && input%2!=0){
            ans++;
        }
    }
    cout << ans << endl;  
    return 0;
}