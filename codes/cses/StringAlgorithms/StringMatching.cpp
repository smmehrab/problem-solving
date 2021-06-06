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

	int matchCount = 0;
    for(int i=0, j=0; i<n; i++) {
        while(j>0 && p[j]!=t[i]) j = pi[j-1];
        if(p[j]==t[i]) j++;
        if(j==m) {
            matchCount++;
			j = pi[j-1]; 
        }
    }
    
    return matchCount;
} 

int main() {
    string t, p;
	cin >> t >> p;
    cout << kmp(t, p) << endl; 
    return 0;
} 