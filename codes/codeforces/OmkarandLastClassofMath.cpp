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
void sieve(int limit)
{
    for (int i = 0; i < limit; i++)
    {
        isPrime[i] = true;
    }

    int number = 2;
    while (number * number <= limit)
    {
        if (isPrime[number])
        {
            for (int index = number * number; index < limit + 1; index += number)
            {
                isPrime[index] = false;
            }
        }
        number += 1;
    }

    for (int index = 2; index < limit + 1; index++)
    {
        if (isPrime[index])
        {
            primeNumbers.push_back(index);
        }
    }
}

// Driver Code
int main()
{
    sieve(PRIME_LIMIT);

    int testCaseCount;
    int testCase;
    long long int n, nTemp, maxFactor;
    scanf("%d", &testCaseCount);
    for (testCase = 1; testCase <= testCaseCount; testCase++)
    {
        scanf("%lld", &n);
        nTemp = n;
        if (n % 2 != 0)
        {
            maxFactor = -1;
            // Logic
            for (auto iterator = primeNumbers.begin(); iterator != primeNumbers.end(); ++iterator)
            {
                int primeNumber = (*iterator);
                int factor = 1;

                while (nTemp % primeNumber == 0)
                {
                    factor *= primeNumber;
                    nTemp /= primeNumber;
                }

                if (factor > maxFactor)
                {
                    maxFactor = factor;
                    if(factor == n && factor == primeNumber){
                        maxFactor=-1;
                    }
                    else if(factor==n){
                        maxFactor = n-primeNumber;
                    }
                }

                if(nTemp==1 || nTemp == 0 || primeNumber>sqrt(n)){
                    break;
                }
            }

            if(maxFactor==-1){
                cout << 1 << " " << (n-1) << endl;
            } else{
                cout << (n-maxFactor) << " " << maxFactor << endl;
            }
        } else{
            cout << (n/2) << " " << (n/2) << endl;
        }
    }
    return 0;
}