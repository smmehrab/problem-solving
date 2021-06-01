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

int testCaseCount, b, k, digitCount;
long long int answer;
string s;
vector<int> digits;
long long int dp[70000][30];

int setBit(int n, int pos)
{
    return n | (1 << pos);
}

bool checkBit(int n, int pos)
{
    return (bool)(n & (1 << pos));
}

long long int solve(int taken, int sum)
{
    if (taken == (1<<digitCount)-1) return sum % k == 0;

    long long int &ret = dp[taken][sum];
    if (ret != -1) return ret;
    
    ret = 0;
    for (int index =0; index<digitCount; index++)
    {
        if (!checkBit(taken, index)) ret += solve(setBit(taken, index), ((sum * b) + digits[index]) % k);
    }

    return ret;
}

int main()
{
    cin >> testCaseCount;
    for (int testCase = 1; testCase <= testCaseCount; testCase++)
    {
        cin >> b >> k;
        cin >> s;

        digitCount = s.size();
        memset(dp, -1, sizeof(dp));
        digits.clear();
        for (char c : s)
        {
            if (c >= 'A' && c <= 'F') digits.push_back(10 + c - 'A');
            else digits.push_back(c - '0');
        }

        answer = solve(0, 0);
        cout << "Case " << testCase << ": " << answer << endl;
    }
    return 0;
}