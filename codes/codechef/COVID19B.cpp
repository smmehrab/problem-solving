#include<bits/stdc++.h>
using namespace std;

int main(){
    int testCases, n, worstCase, bestCase, t, x;
    cin >> testCases;
    while(testCases--){
        cin >> n;
        vector<int> v(n);
        for(int &x : v) cin >> x;
        
        bestCase = n; 
        worstCase = 0;

        map<pair<int,int>, vector<int>> pairsMeetingAt;
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++) {
                if(v[i]>v[j]){
                    t= ((j-i)*120)/(v[i]-v[j]);
                    x = i*120+v[i]*t;
                    assert(120*i+v[i]*t == 120*j+v[j]*t);
                    pairsMeetingAt[{t,x}].push_back(i);
                    pairsMeetingAt[{t,x}].push_back(j);
                }
            }
        }

        for(int infectedAthlete=0; infectedAthlete<n; infectedAthlete++){
            vector<bool>isInfected(n, false);
            isInfected[infectedAthlete]=true;

            for(auto entry : pairsMeetingAt){
                bool spread = false;
                for(int athlete : entry.second) spread |= isInfected[athlete];
                if(spread){
                    for(int athlete : entry.second) isInfected[athlete]=true;
                }
            }

            int totalInfected=0;
            for(int athlete=0; athlete<n; athlete++){
                if(isInfected[athlete]) totalInfected ++;
            }

            bestCase = min(bestCase, totalInfected);
            worstCase = max(worstCase, totalInfected);
        }

        cout << bestCase << " " << worstCase << endl;
    }
    return 0;
}