#include <bits/stdc++.h>
using namespace std;

#define LIMIT 100100

long long int tree[LIMIT * 4];
long long int propagation[LIMIT * 4];

void updateCount(int current, int start, int end, int x, int y)
{
    if (x > end || y < start)
    {
        return;
    }

    else if (start >= x && end <= y)
    {
        tree[current] += (end - start + 1);
        propagation[current] += 1;
        return;
    }

    else
    {
        int left = current * 2;
        int right = (current * 2) + 1;
        int mid = (start + end) / 2;

        updateCount(left, start, mid, x, y);
        updateCount(right, mid + 1, end, x, y);

        tree[current] = tree[left] + tree[right] + (end - start + 1) * propagation[current];
    }
}

long long int query(int current, int start, int end, int x, int y, long long int carry = 0)
{
    if (x > end || y < start)
    {
        return 0;
    }

    else if (start >= x && end <= y)
    {
        return tree[current] + carry * (end - start + 1);
    }

    else
    {
        int left = current * 2;
        int right = (current * 2) + 1;
        int mid = (start + end) / 2;

        long long int leftSum = query(left, start, mid, x, y, carry + propagation[current]);
        long long int rightSum = query(right, mid + 1, end, x, y, carry + propagation[current]);

        return leftSum + rightSum;
    }
}

int main()
{
    int testCaseCount, testCase;
    int n, q, a, b, p;

    scanf("%d", &testCaseCount);
    for (testCase = 1; testCase <= testCaseCount; testCase++)
    {
        printf("Case %d:\n", testCase);
        scanf("%d %d", &n, &q);

        memset(tree, 0, sizeof tree);
        memset(propagation, 0, sizeof propagation);
        for (int segment = 0; segment < n; segment++)
        {
            scanf("%d %d", &a, &b);
            updateCount(1, 0, n - 1, a, b);
        }

        for (int index = 0; index < q; index++)
        {
            scanf("%d", &p);
            printf("%lld\n", query(1, 0, n - 1, p, p, 0));
        }
    }
    return 0;
}