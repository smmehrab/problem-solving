#include<bits/stdc++.h>
using namespace std;

int main() {
    int testCaseCount, n, k, minK;
    bool fallShort;

    cin >> testCaseCount;
    for(int testCase=1; testCase<=testCaseCount; testCase++) {
        cin >> n;

        vector<int> rungs(n);
        for(int &rung : rungs) 
            cin >> rung;

        vector<int> jumps(n);
        for(int i=0; i<n; i++)
            jumps[i] = (i==0) ? rungs[i] : rungs[i]-rungs[i-1];
        sort(jumps.begin(), jumps.end(), greater<int>());

        k = -1;
        fallShort = false;
        for(int jump : jumps) {
            if(k==-1) {
                k = jump;
                minK = k;
            }

            if(jump==k)
                k--;
            else if(jump>k) {
                fallShort = true;
                break;
            }
        }

        minK += fallShort; 
        cout << "Case " << testCase << ": " << minK << endl;
    }
    return 0;
}