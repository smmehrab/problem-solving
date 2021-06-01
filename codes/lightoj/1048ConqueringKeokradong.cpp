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

vector<int> findPlan(int maxWalkPerDay, vector<int>& distances, int n, int k) {
    vector<int> plan;

    int remainingDays = k+1;
    int remainingDistance = n+1;
    int camp = 0;

    while(camp <= n) {
        int go = 0;
        while(camp <= n && go + distances[camp] <= maxWalkPerDay) {
            if(remainingDays == remainingDistance) {
                plan.push_back(go+distances[camp++]);
                while(camp <= n)
                    plan.push_back(distances[camp++]);
                return plan;
            }

            go += distances[camp++];
            remainingDistance--;
        }

        plan.push_back(go);
        remainingDays--;
    }

    return plan;
}

bool isPossible(int maxWalkPerDay, vector<int>& distances, int n, int k) {
    int remainingDays = k+1;
    int remainingDistance = n+1;
    int camp = 0;

    while(camp <= n) {
        int go = 0;
        while(camp <= n && go + distances[camp] <= maxWalkPerDay) {
            if(remainingDays == remainingDistance) return true;
            go += distances[camp++];
            remainingDistance--;
        }
        remainingDays--;
    }

    return (remainingDays == remainingDistance);
}

int binarySearch(int low, int high, vector<int>& distances, int n, int k) {
    int maxWalkPerDay;
    while(low <= high) {
        int mid = (low + high) >> 1;
        if(isPossible(mid, distances, n, k)) {
            maxWalkPerDay = mid;
            high = mid-1;
        }
        else 
            low = mid+1;
    }
    return maxWalkPerDay;
}

// Driver
int main() {
    int testCaseCount, n, k, totalDistance, maxDistance, maxWalkPerDay;
    vector<int> distances;
    vector<int> plan;

    cin >> testCaseCount;
    for(int testCase=1; testCase<=testCaseCount; testCase++) {
        // Taking Input
        cin >> n >> k;
        distances.clear();
        distances = vector<int>(n+1);
        for(int &distance : distances) 
            cin >> distance;

        // Finding Total Distance (Upper) & Maximum Distance (Lower)
        totalDistance = 0;
        maxDistance = -1;
        for(int distance : distances) {
            totalDistance += distance;
            maxDistance = max(maxDistance, distance);
        }

        // Processing Actual Solution
        maxWalkPerDay = binarySearch(maxDistance, totalDistance, distances, n, k);
        plan = findPlan(maxWalkPerDay, distances, n, k);

        // Output
        cout << "Case " << testCase << ": " << maxWalkPerDay << endl;
        for(int walkOnDay : plan)
            cout << walkOnDay << endl;
    }

    return 0;
}