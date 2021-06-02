/*
************************************************
username    :   smmehrab
fullname    :   s.m.mehrabul islam
email       :   mehrab.24csedu.001@gmail.com
institute   :   university of dhaka, bangladesh
session     :   2017-2018
************************************************
*/
#include<bits/stdc++.h>
using namespace std;

#define INF INT_MAX

int estimate(int capacity, vector<int>& vessels) {
    int container=0, count=1;
    for(int vessel : vessels) {
        if(vessel>capacity) 
            return INF;
        else if(container+vessel<=capacity) 
            container += vessel;
        else {
            count++;
            container = vessel;
        }
    }
    return count;
}

int binarySearch(int n, int m, vector<int>& vessels) {
    int low = -1, high = 0;
    for(int vessel : vessels) {
        low = max(low, vessel);
        high += vessel;
    }

    if(m==1) 
        return high;
    if(n==m)
        return low;

    int capacity, minCapacity, containerCount;
    while(low<high) {
        capacity = (low + (high-low)/2);
        containerCount = estimate(capacity, vessels);
        if(containerCount > m) 
            low = capacity+1;
        else 
            minCapacity = high = capacity;
    }
    return minCapacity;
}

int main() {
    int testCaseCount, n, m, minCapacity;
    cin >> testCaseCount;
    for(int testCase=1; testCase<=testCaseCount; testCase++) {
        cin >> n >> m;

        vector<int> vessels(n);
        for(int &vessel : vessels) 
            cin >> vessel;

        minCapacity = binarySearch(n, m, vessels);
        cout << "Case " << testCase << ": " << minCapacity << endl;
    }
    return 0;
}