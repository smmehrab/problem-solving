#include <bits/stdc++.h>
using namespace std;

long long int absolute(long long int n)
{
    return n > 0 ? n : -n;
}

long long int gcd(long long int a, long long int b)
{
    if (b == 0)
        return a;
    else
        return gcd(b, a % b);
}

int main()
{
    int testCaseCount;
    int testCase;
    long long int ax, ay, bx, by, ans;
    scanf("%d", &testCaseCount);
    for (testCase = 1; testCase <= testCaseCount; testCase++)
    {
        scanf("%lld %lld %lld %lld", &ax, &ay, &bx, &by);
        ans = gcd(absolute(ax - bx), absolute(ay - by)) + 1;
        printf("Case %d: %lld\n", testCase, ans);
    }
    return 0;
}