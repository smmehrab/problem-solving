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

#define PRIME_LIMIT 1000005

vector<long long int> sieve() {
    vector<long long int> primes;
    vector<bool> isPrime(PRIME_LIMIT, true);

    for(long long int i=3; i<PRIME_LIMIT; i+=2) {
        if(isPrime[i]) {
            for(long long int j=(i*i); j<PRIME_LIMIT; j+=(2*i))
                isPrime[j] = false;
        }
    }
    
    primes.push_back(2);
    for(int i=3; i<PRIME_LIMIT; i+=2) {
        if(isPrime[i]) 
            primes.push_back(i);
    }

    return primes;
}

int main() {
    vector<long long int> primes = sieve();
    int testCaseCount, power;
    long long int n, divisorCount;

    cin >> testCaseCount;
    for(int testCase=1; testCase <= testCaseCount; testCase++) {
        cin >> n;

        divisorCount = 1;
        for(long long int prime : primes){
            if(n==1 || (prime*prime)>n)
                break;
            
            else if(n>1 && n%prime==0){
                power=0;
                while(n>1 && n%prime==0){
                    power++;
                    n /= prime;
                }
                divisorCount *= (power+1);
            }
        }
    
        if(n != 1) {
            power = 1;
            divisorCount *= (power+1);
        }
        
        cout << "Case " << testCase << ": " << (divisorCount-1) << endl;
    }

    return 0;
}