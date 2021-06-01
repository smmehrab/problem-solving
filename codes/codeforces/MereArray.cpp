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

long long int gcd(long long int a,long long int b)
{
    if(b==0) {return a;}
    return gcd(b,a%b);
}

int main()
{
    int t, n, d;
    string ans;
    long long int a[200100], b[200100];
    cin >> t;
    while(t--){
        cin >> n;
        for(int i=0; i<n; i++){
            cin >> a[i];
            b[i] = a[i];
        }

        sort(b, b+n);
        for(int i=0; i<n; i++){
            if(i==0) d=a[i];
            else if(a[i]<d) d=a[i];
        }
        
        ans = "YES";
        for(int i=0; i<n; i++){
            if(a[i]==b[i]) continue;
            else if(gcd(a[i],d)!=d){
                ans = "NO";
                break;
            }            
        }

        cout << ans << endl;
    }
    return 0;
}