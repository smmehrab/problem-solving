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

void init(int current, int start, int end)
{
    if (start == end) {
        tree[current] = arr[start];
        return;
    }
    int left = current * 2;
    int right = (current * 2) + 1;
    int mid = (start + end) / 2;
    init(left, start, mid);
    init(right, mid + 1, end);
    tree[current] = min(tree[left], tree[right]);
}

int query(int current, int start, int end, int i, int j)
{
    if (i > end || j < start)
        return INT_MAX; 
    if (start >= i && end <= j)
        return tree[current]; 
    int left = current * 2;
    int right = current * 2 + 1;
    int mid = (start + end) / 2;
    int leftMin = query(left, start, mid, i, j);
    int rightMin = query(right, mid + 1, end, i, j);
    return min(leftMin, rightMin);
}

int main()
{
    int testCaseCount, testCase;
    int n, q, i, j;

    scanf("%d", &testCaseCount);
    for (testCase = 1; testCase <= testCaseCount; testCase++)
    {
        printf("Case %d:\n", testCase);
        scanf("%d %d", &n, &q);

        for(int index=1; index<=n; index++){
            scanf("%d", &arr[index]);
        }

        init(1, 1, n);

        for(int index=0; index<q; index++){
            scanf("%d %d", &i, &j);
            printf("%d\n", query(1, 1, n, i, j));
        }
    }
    return 0;
}