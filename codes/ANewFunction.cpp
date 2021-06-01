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
    int testCase;
    long long int query;
    int answer;

    scanf("%d", &testCaseCount);

    for(testCase=1; testCase <= testCaseCount; testCase++){
        scanf("%lld", &query);
        int queryLimit = sqrt(query);
        answer=1;

        // Logic
        for(auto iterator=primeNumbers.begin(); iterator!=primeNumbers.end(); ++iterator){
            int primeNumber=(*iterator);
            int power=0;

            if(query==1 || primeNumber > query || primeNumber>queryLimit){
                break;
            } 
            else if(query%primeNumber==0){
                while(query%primeNumber==0){
                    power++;
                    query/=primeNumber;
                }
                answer*=(power+1);
            }
        }
    
        if(query != 1) {
            answer*=2;
        }
        
        answer -= 1;
        printf("Case %d: %lld\n",testCase,answer);
    }
    return 0; 
}