#include <bits/stdc++.h>
using namespace std;

int main() {
    int testCaseCount, n, minimumPopulation;
	cin >> testCaseCount;
	for(int testCase=1; testCase<=testCaseCount; testCase++) {
		cin >> n;

        map<int,int> count;
		for(int i=0, answer; i<n; i++) {
            cin >> answer;
            count[answer]++;
        }

        minimumPopulation = 0;
        for (auto entry : count) 
            minimumPopulation += (ceil(entry.second/(1.00*(entry.first+1))) * (entry.first+1));
        
        cout << "Case " << testCase << ": " << minimumPopulation << endl;
	}

    return 0;
}