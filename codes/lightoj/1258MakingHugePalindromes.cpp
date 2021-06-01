/*
************************************************
username    :   smmehrab
fullname    :   s.m.mehrabul islam
email       :   mehrab.24csedu.001@gmail.com
institute   :   university of dhaka, bangladesh
session     :   2017-2018
************************************************
*/
#include <bits/stdc++.h> 
using namespace std;

void computePi(string p, int m, vector<int>& pi) { 
	int k = 0; 
	pi[0] = 0; 
    for(int i=1; i<m; i++) {
        while(k>0 && p[k]!=p[i]) k=pi[k-1];
        if(p[k]==p[i]) k++;
        pi[i] = k;
    }
} 

int kmp(string t, string p) { 
	int n = t.size();
    int m = p.size(); 

	vector<int> pi(m, 0); 
	computePi(p, m, pi); 

    int k = 0;
    for(int i=0; i<n; i++) {
        while(k>0 && p[k]!=t[i]) k = pi[k-1];
        if(p[k]==t[i]) k++;
    }

    return k;
} 

int main() {
    int testCaseCount, answer, n, k, match;
    string s, sRev;
    
    cin >> testCaseCount;
    for(int testCase=1; testCase<=testCaseCount; testCase++) {
        cin >> s;
        n = s.size();
        
        sRev = s;
        reverse(sRev.begin(), sRev.end());
        
        vector<int> pi(n, 0);
        
        computePi(sRev, n, pi);
        match = kmp(s, sRev);

        // for(int i=0; i<n; i++) 
        //     cout << sRev[i] << " ";
        // cout << endl;
        // for(int i=0; i<n; i++) 
        //     cout << pi[i] << " ";
        // cout << endl;
        
        answer = (2*n)-match;
        cout << "Case " << testCase << ": " <<  answer << endl;
    }
	
    return 0;
} 