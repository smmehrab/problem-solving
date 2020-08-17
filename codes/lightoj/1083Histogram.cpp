#include <bits/stdc++.h>
#include <stack>
using namespace std;

int main()
{
    int testCaseCount, testCase, n;

    scanf("%d", &testCaseCount);
    for (testCase = 1; testCase <= testCaseCount; testCase++)
    {
        scanf("%d", &n);

        stack<long long int> barStack;
        long long int height[n], area, maxArea = -1;

        for (int bar = 0; bar < n; bar++)
        {
            scanf("%lld", &height[bar]);
            if (barStack.empty() || height[barStack.top()] <= height[bar])
            {
                barStack.push(bar);
            }
            else
            {
                while (!barStack.empty() && height[barStack.top()] > height[bar])
                {
                    int barTop = barStack.top();
                    barStack.pop();
                    if (barStack.empty())
                    {
                        area = height[barTop] * bar;
                    }
                    else
                    {
                        area = height[barTop] * (bar - barStack.top() - 1);
                    }
                    maxArea = max(maxArea, area);
                }

                barStack.push(bar);
            }
        }

        while (!barStack.empty())
        {
            int barTop = barStack.top();
            barStack.pop();
            if (barStack.empty())
            {
                area = height[barTop] * n;
            }
            else
            {
                area = height[barTop] * (n - barStack.top() - 1);
            }
            maxArea = max(maxArea, area);
        }

        printf("Case %d: %lld\n", testCase, maxArea);
    }

    return 0;
}