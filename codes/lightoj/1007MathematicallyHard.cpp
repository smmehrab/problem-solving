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

const int LIMIT = 5000005;
bool isPrime[LIMIT];
unsigned long long int phi[LIMIT];

// Modified from Sieve
void generatePhi(int limit)
{
    for (int index = 0; index < limit; index++)
    {
        isPrime[index] = true;
        phi[index] = index;
    }

    int number = 2;
    while (number<= limit)
    {
        if (isPrime[number])
        {
            for (int index = number; index < limit; index += number)
            {
                isPrime[index] = false;
                phi[index] = (phi[index]/number)*(number-1);
            }
        }
        number++;
    }

    for (int index = 2; index < limit; index++)
    {
        phi[index] *= phi[index];
        phi[index] += phi[index-1];
    }
}

// Driver Code
int main()
{
    generatePhi(LIMIT);
    int testCaseCount;
    int testCase;
    unsigned long long int a, b, c;
    scanf("%d", &testCaseCount);
    for (testCase = 1; testCase <= testCaseCount; testCase++)
    {
        scanf("%llu %llu", &a, &b);
        c = phi[b] - phi[a-1];
        printf("Case %d: %llu\n", testCase, c);
    }
    return 0;
}