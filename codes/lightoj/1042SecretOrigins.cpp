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
#include <string>
#include <map>
#include <algorithm>
#include <iostream>
#include <iomanip>
#include <bitset>
using namespace std;

// Driver Code
int main()
{
    int testCaseCount, testCase;
    long long int n, answer;
    string nBinary;
    cin >> testCaseCount;
    for (testCase = 1; testCase <= testCaseCount; testCase++)
    {
        cin >> n;
        answer = 0;
        nBinary = bitset<32>(n).to_string(); 
        next_permutation(nBinary.begin(), nBinary.end());
        reverse(nBinary.begin(), nBinary.end());
        for (int i = 0; i < nBinary.size(); i++)
        {
            if (nBinary[i] == '1')
            {
                answer += pow(2, i);
            }
        }
        cout << "Case " << testCase << ": " << answer << endl;
    }
    return 0;
}