#include <bits/stdc++.h>
using namespace std;

long long int solve(int n, int a[], long long int p) {
    vector<long long int> dp(n, 1);
    for (int i = 0; i < n-1; i++) {
        for (int j = i+1; j < n; j++) {
            if (a[j] > a[i])
                dp[j]+=dp[i];
        }
    }

    long long int ans = 0;
    for (int i = 0; i < n; i++) 
        ans = (ans+dp[i])%p;

    return ans;
}

int main()
{
    int testCaseCount, n, a[100100];
    long long int p = 1000000007;
    cin >> testCaseCount;
    for(int testCase = 1; testCase <= testCaseCount; testCase++){
        cin >> n;
        for(int i=0; i<n; i++) cin >> a[i];
        cout << "Case " << testCase << ": " << solve(n, a, p) << endl;
    }
    return 0;
}


#include <bits/stdc++.h>
using namespace std;
 
#define LIMIT 100001
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
 
void update(int current, int start, int end, int i, int toBeAdded)
{
    if (i > end || i < start)
    {
        return;
    }
    if (start >= i && end <= i)
    {
        if (toBeAdded == 0)
        {
            oldValue = tree[current];
            tree[current] = toBeAdded;
        }
        else
        {
            tree[current] += toBeAdded;
        }
        return;
    }
    int left = current * 2;
    int right = current * 2 + 1;
    int mid = (start + end) / 2;
    update(left, start, mid, i, toBeAdded);
    update(right, mid + 1, end, i, toBeAdded);
    tree[current] = tree[left] + tree[right];
}
 
int main()
{
    int testCaseCount, testCase;
    int n, q, i, j, v, t;
 
    scanf("%d", &testCaseCount);
    for (testCase = 1; testCase <= testCaseCount; testCase++)
    {
        printf("Case %d:\n", testCase);
        scanf("%d", &n);
 
        for (int index = 1; index <= n; index++)
            scanf("%d", &arr[index]);
        
 
        init(1, 1, n);
 
        for (int index = 0; index < q; index++)
        {
            scanf("%d", &t);
            if (t == 1)
            {
                scanf("%d", &i);
                update(1, 1, n, i + 1, 0);
                printf("%d\n", oldValue);
            }
            else if (t == 2)
            {
                scanf("%d %d", &i, &v);
                update(1, 1, n, i + 1, v);
            }
            else if (t == 3)
            {
                scanf("%d %d", &i, &j);
                printf("%d\n", query(1, 1, n, i + 1, j + 1));
            }
        }
    }
    return 0;
}