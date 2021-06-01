#include <bits/stdc++.h>
using namespace std;

#define maxn 20000
int cnt1, cnt2, k, n, num;
int a1[maxn], a2[maxn], b[20];

void dfs(int sum, int x) {
    if (x == num) {
        (num == n/2) ? a1[cnt1++] = sum : a2[cnt2++] = sum;
        return;
    }
    for (int i = 0; i < 3; i++)
        dfs(sum + b[x] * i, x + 1);
}

bool sreach(int x) {
    int low = 0, high = cnt2 - 1;

    while (low <= high) {
        int mid = (low + high) / 2;
        if (a1[x] + a2[mid] == k)
            return true;
        else if (a1[x] + a2[mid] > k)
            high = mid - 1;
        else
            low = mid + 1;
    }

    return false;
}

int main() {
    int testCaseCount;
    cin >> testCaseCount;

    for(int testCase=1; testCase<=testCaseCount; testCase++) {
        cin >> n >> k;
        for (int i = 0; i < n; i++)
            scanf("%d", &b[i]);

        cnt1 = cnt2 = 0;
        num = n / 2;
        dfs(0, 0);

        num = n;
        dfs(0, n / 2);
        sort(a2, a2 + cnt2);

        int i;
        for (i = 0; i < cnt1; i++) {
            if (sreach(i))
                break;
        }

        cout << "Case " << testCase << ": " << ((i==cnt1) ? "No" : "Yes") << endl;
    }
    return 0;
}