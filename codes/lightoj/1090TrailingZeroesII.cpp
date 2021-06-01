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
    int n, r, p, q;
    int answer;
    int n5, n2, r5, r2, nr, nr5, nr2, p5, p2;

    scanf("%d", &testCaseCount);

    for (testCase = 1; testCase <= testCaseCount; testCase++)
    {
        scanf("%d %d %d %d", &n, &r, &p, &q);

        /* Logic */
        nr = n - r;

        // For n
        n5 = 0;
        for (int dividend = 5, power = 0; power < n / 4; dividend *= 5, power++)
        {
            if (n / dividend == 0)
                break;
            n5 += n / dividend;
        }

        n2 = 0;
        for (int dividend = 2, power = 0; power < n; dividend *= 2, power++)
        {
            if (n / dividend == 0)
                break;
            n2 += n / dividend;
        }

        // For r
        r5 = 0;
        for (int dividend = 5, power = 0; power < r / 4; dividend *= 5, power++)
        {
            if (r / dividend == 0)
                break;
            r5 += r / dividend;
        }

        r2 = 0;
        for (int dividend = 2, power = 0; power < r; dividend *= 2, power++)
        {
            if (r / dividend == 0)
                break;
            r2 += r / dividend;
        }

        // For nr
        nr5 = 0;
        for (int dividend = 5, power = 0; power < nr / 4; dividend *= 5, power++)
        {
            if (nr / dividend == 0)
                break;
            nr5 += nr / dividend;
        }

        nr2 = 0;
        for (int dividend = 2, power = 0; power < nr; dividend *= 2, power++)
        {
            if (nr / dividend == 0)
                break;
            nr2 += nr / dividend;
        }

        // For pq
        p5 = 0;
        p2 = 0;
        if ((p % 2 == 0 || p % 5 == 0))
        {
            while (p % 5 == 0)
            {
                p /= 5;
                p5++;
            }
            p5 *= q;

            while (p % 2 == 0)
            {
                p /= 2;
                p2++;
            }
            p2 *= q;
        } 

        if(p5!=0 || p2!=0){
            answer = min(((n5 + p5) - (r5 + nr5)), (((n2 + p2) - (r2 + nr2))));
        } else{
            answer = min(n5 - r5 - nr5, n2-r2-nr2);
        }

        if (answer < 0)
            answer = 0;
        
        printf("Case %d: %d\n", testCase, answer);
    }
    return 0;
}