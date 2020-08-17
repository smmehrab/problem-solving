#include <bits/stdc++.h>
using namespace std;

int dp[12][12];
char s[12];

int recurse(int pos, int smallFlag, int sum)
{

    if (sum > 10)
        return 0;
    if (s[pos] == '\0')
        return sum == 10;

    int &ret = dp[pos][sum];
    if (ret != -1 && smallFlag)
        return ret;

    int limit = 9;
    if (smallFlag == 0)
        limit = s[pos] - '0';

    ret = 0;
    for (int option = 0; option <= limit; option++)
    {
        ret += recurse(pos + 1, (option < limit) | smallFlag == 1, sum + option);
    }

    return ret;
}

int findCount(int n)
{
    sprintf(s, "%d", n);
    memset(dp, -1, sizeof(dp));
    return recurse(0, 0, 0);
}

int solve(int k){
    int low = 19;
    int high = 1e9;
    int mid, countOfDesiredNumbers, answer;
    
    while (low <= high)
    {
        mid = (low + high) / 2;
        countOfDesiredNumbers = findCount(mid);
        if (countOfDesiredNumbers >= k)
        {
            answer = mid;
            high = mid - 1;
        }
        else{
            low = mid + 1;
        }
    }

    return answer;
}

int main()
{ 
    int k;
    cin >> k;
    cout << solve(k) << endl;
    return 0;
}