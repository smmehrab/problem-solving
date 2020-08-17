#include <bits/stdc++.h>
#include <stdio.h>
#include <math.h>
#include <stdbool.h>
#include <string>
#include <map>
using namespace std;

#define LIMIT 100100
int arr[LIMIT];
int tree[LIMIT * 3];
int oldValue;

void init(int current, int start, int end)
{
    if (start == end)
    {
        tree[current] = arr[start];
        return;
    }
    int left = current * 2;
    int right = (current * 2) + 1;
    int mid = (start + end) / 2;
    init(left, start, mid);
    init(right, mid + 1, end);
    tree[current] = tree[left] + tree[right];
}

int query(int current, int start, int end, int i, int j)
{
    if (i > end || j < start)
        return 0;
    if (start >= i && end <= j)
        return tree[current];
    int left = current * 2;
    int right = current * 2 + 1;
    int mid = (start + end) / 2;
    int leftSum = query(left, start, mid, i, j);
    int rightSum = query(right, mid + 1, end, i, j);
    return leftSum + rightSum;
}

void update(int current, int start, int end, int i, int newvalue)
{
    if (i > end || i < start)
    {
        return;
    }
    if (start >= i && end <= i)
    {
        if (newvalue == 0)
        {
            oldValue = tree[current];
            tree[current] = newvalue;
        }
        else
        {
            tree[current] += newvalue;
        }
        return;
    }
    int left = current * 2;
    int right = current * 2 + 1;
    int mid = (start + end) / 2;
    update(left, start, mid, i, newvalue);
    update(right, mid + 1, end, i, newvalue);
    tree[current] = tree[left] + tree[right];
}

int main()
{
    int testCaseCount, testCase;
    int n, q, i, j, v;
    char code;

    scanf("%d", &testCaseCount);
    for (testCase = 1; testCase <= testCaseCount; testCase++)
    {
        printf("Case %d:\n", testCase);
        cin >> n >> q;

        for (int index = 1; index <= n; index++)
        {
            cin >> arr[index];
        }

        init(1, 1, n);

        for (int index = 0; index < q; index++)
        {
            cin >> code;
            if (code == '1')
            {
                cin >> i;
                update(1, 1, n, i + 1, 0);
                cout << oldValue << endl;
            }
            else if (code == '2')
            {
                cin >> i >> v;
                update(1, 1, n, i + 1, v);
            }
            else if (code == '3')
            {
                cin >> i >> j;
                cout << query(1, 1, n, i + 1, j + 1) << endl;
            }
        }
    }
    return 0;
}