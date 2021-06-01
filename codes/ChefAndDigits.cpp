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

int dp[20][2][2], counter[20], a[20];
char s[20];

int recurse(int pos, int smallFlag, int zeroFlag)
{
    if (s[pos] == '\0')
    {
        for (int digit = 0; digit < 10; digit++)
        {
            if (counter[digit] == a[digit])
            {
                return 0;
            }
        }
        return 1;
    }

    int &ret = dp[pos][smallFlag][zeroFlag];
    if (ret != -1)
        return ret;

    int limit = 9;
    if (smallFlag == 0)
        limit = s[pos] - '0';

    ret = 0;
    if(zeroFlag==0) {
        ret += recurse(pos+1, 0<limit || smallFlag==1, zeroFlag);
    } else{
        counter[0]++;
        ret += recurse(pos+1, 0<limit || smallFlag==1, zeroFlag);
        counter[0]--;
    }

    for (int option = 1; option <= limit; option++)
    {
        counter[option]++; 
        ret += recurse(pos + 1, option < limit || smallFlag == 1, 1);
        counter[option]--; 
    }

    return ret;
}

int solve(int n)
{
    sprintf(s, "%d", n);
    memset(dp, -1, sizeof(dp));
    memset(counter, 0, sizeof(counter));
    return recurse(0, 0, 0);
}

int main()
{
    int testCaseCount, l, r, answer;
    cin >> testCaseCount;
    while (testCaseCount--)
    {
        cin >> l >> r;
        for (int digit = 0; digit < 10; digit++)
            cin >> a[digit];
        answer = solve(r) - solve(l - 1);
        cout << answer << endl;
    }
    return 0;
}

num_length = length(x)

    for len in range[1 to num_length - 1]:
        for mask in range[1 to 2^10]:
           index = log2(mask & -mask) // this gives the first bit set in mask
           new_mask = mask ^ (1<<index)

           for count in range[1 to len]:
               if count == a[index]
                   continue
               if index == 0
                   if new_mask>0:
                      dp[len][mask] += dp[len - count][new_mask] * C[len-1][count]
               else
                   dp[len][mask] += dp[len-count][new_mask] * C[len][count]