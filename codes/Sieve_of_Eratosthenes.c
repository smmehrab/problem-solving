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

void SieveOfEratosthenes(int n){
    bool prime[n+1];
    memset(prime, true, sizeof(prime));

    for (int p=2; p*p<=n; p++) if (prime[p] == true) for(int i=p*2;i<=n;i+=p)  prime[i]=false;
    for (int p=2; p<=n; p++) if (prime[p]) cout << p << " ";
}

int main()
{
    int n = 100000;
    cout << "Following are the prime numbers smaller than or equal to " << n << endl;
    SieveOfEratosthenes(n);
    return 0;
}
