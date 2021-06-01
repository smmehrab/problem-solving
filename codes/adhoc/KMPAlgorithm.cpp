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

void kmp(string t, string p) { 
	int n = t.size();
    int m = p.size(); 

	vector<int> pi(m, 0); 
	computePi(p, m, pi); 

    for(int i=0, j=0; i<n; i++) {
        while(j>0 && p[j]!=t[i]) j = pi[j-1];
        if(p[j]==t[i]) j++;
        if(j==m) {
            cout << "Found Pattern At Index: " << (i-m+1) << endl; 
			j = pi[j-1]; 
        }
    }
} 

int main() {
    string t, p;

    cout << "Enter T: (Text)" << endl;
    getline(cin, t);
    cout << "Enter P: (Pattern)" << endl;
    getline(cin, p);

    kmp(t, p); 
	
    return 0;
} 