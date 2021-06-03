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

int main() {
    int testCaseCount, n;
    int a, b, c, count;
    cin >> testCaseCount;
    for (int testCase = 1; testCase <= testCaseCount; testCase++) {
        cin >> n;

        vector<int> sticks(n);
        for(int &stick : sticks) 
            cin >> stick;
        sort(sticks.begin(), sticks.end());
        
        count = 0;
        for(int i=0; i<n-2; i++){
            a = sticks[i];
            for(int j=i+1, k; j<n-1; j++) {
                b = sticks[j];
                if(sticks[j+1] >= a+b) 
                    continue;
                else if(sticks[n-1] < a+b)
                    k = n-1;
                else 
                    k = upper_bound(sticks.begin()+j+1, sticks.end(), a+b-1)-sticks.begin()-1;
                count += (k-j);
            }
        }
        
        cout << "Case " << testCase << ": " << count << endl;
    }
    return 0;
}