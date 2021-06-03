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

long long int findTrailingZeroes(long long int number) {
    long long int traillingZeros = 0;
    for (long long int i=5; i<=number; i*=5) 
        traillingZeros += (number/i);
    return traillingZeros;
}

long long int binarySearch(long long int q) {
    long long int low = 1, mid, high = LLONG_MAX; 
    long long int trailingZeroes, n = -1;
    while(low <= high) {
        mid = (low + high) / 2;
        trailingZeroes = findTrailingZeroes(mid);
        if(trailingZeroes > q) 
            high = mid-1;
        else if(trailingZeroes < q) 
            low = mid+1;
        else 
            n = mid, high = mid-1;
    }
    return n;
}

int main() {
    int testCaseCount;
    long long int q, n;
    cin >> testCaseCount;
    for (int testCase = 1; testCase <= testCaseCount; testCase++) {
        cin >> q;
        n = binarySearch(q);
        cout << "Case " << testCase << ": " << (n==-1 ? "impossible" : to_string(n)) << endl;
    }
    return 0;
}