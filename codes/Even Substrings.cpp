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
    char s[65300];
    long long int n,i,ans=0;
    cin >> n >> s+1;
	for(i=1;i<=n;++i)
        if(s[i]%2==0) ans+=i;
	cout << ans << endl;
	return 0;
}
