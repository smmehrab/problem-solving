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

int main()
{
    int n,a[100011],i,max;
    memset(a,0,sizeof(a));

    cin >> n;
    max=n;

    while(n--){
        cin >> i;
        a[i]=1;
        while(max&&a[max])
            cout << max-- << " ";
        cout << endl;
    }

    return 0;
}
