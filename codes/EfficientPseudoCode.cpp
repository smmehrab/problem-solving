#include <bits/stdc++.h>
#include <stdio.h>
#include <math.h>
#include <stdbool.h>
using namespace std;

#define MODULO 1000000007

const int PRIME_LIMIT = 1000001;
bool isPrime[PRIME_LIMIT];
vector<long long int> primeNumbers;

// Sieve Of Eratosthenes
void sieve(int limit) {
	for(int i = 0; i < limit; i++){
        isPrime[i] = true;
    }

	int number = 2;
	while (number * number <= limit) {
		if (isPrime[number]) {
			for(int index = number * number; index < limit + 1; index += number) {
                isPrime[index] = false;
			}
		}
		number += 1;
	}

	for(int index = 2; index < limit + 1; index++) {
        if (isPrime[index]){
            primeNumbers.push_back(index);
        }
	}
}

// Driver Code
int main(){
    sieve(PRIME_LIMIT); 

    int testCaseCount;
    long long int n, m;

    scanf("%d", &testCaseCount);

    for(int testCase=1; testCase <= testCaseCount; testCase++){
        scanf("%lld %lld", &n, &m);
        long long int primeLimit = sqrt(n);
        long long int answer = 1;

        if(n<PRIME_LIMIT && isPrime[n]){
            
        }

        // Logic
        for(auto iterator=primeNumbers.begin(); iterator!=primeNumbers.end(); ++iterator){
            long long int primeNumber=(*iterator);
            long long int power=0;

            if(n==1 || primeNumber > n || primeNumber>primeLimit){
                break;
            }
            else if(n%primeNumber==0){
                while(n%primeNumber==0){
                    power++;
                    n/=primeNumber;
                }
                power*=m;
                answer*= (pow(primeNumber, power+1)-1)/(primeNumber-1);
            }
        }

        // answer %= MODULO;
        printf("Case %d: %lld\n",testCase,answer);
    }
    return 0; 
}