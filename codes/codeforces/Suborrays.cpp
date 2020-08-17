#include <bits/stdc++.h>
using namespace std;

int main()
{
    int testCaseCount, n;
    cin >> testCaseCount;
    for (int testCase = 1; testCase <= testCaseCount; testCase++)
    {
        cin >> n;
        for(int i=1; i<=n; i++){
            cout << i;
            if(i!=n) cout << " ";
        }
       cout << endl;
    }
    return 0;
}