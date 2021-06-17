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

int dp[51][51][51];

bool isVowel(char c) {
    return (c=='A' || c=='E' || c=='I' || c=='O' || c=='U');
}

int solve(int index, int consonants, int vowels, string s) {
    if(index>=s.size()) 
        return 0;

    int &verdict = dp[index][consonants][vowels];
    if(verdict==-1) {
        if(s[index]=='?') {
            int option1 = (consonants+1<5) ? solve(index+1, consonants+1, 0, s) : 1;
            int option2 = (vowels+1<3) ? solve(index+1, 0, vowels+1, s) : 1;
            verdict = (option1==0 && option2==0) ? 0 : ((option1==1 && option2==1) ? 1 : 2);
        }
        else if(isVowel(s[index])) 
            verdict = (vowels+1<3) ? solve(index+1, 0, vowels+1, s) : 1;
        else 
            verdict = (consonants+1<5) ? solve(index+1, consonants+1, 0, s) : 1;
    }
    return verdict;
}

int main() {
    int testCaseCount, verdict;
    string s;
    cin >> testCaseCount;
    for(int testCase=1; testCase<=testCaseCount; testCase++) {
        cin >> s;
        memset(dp, -1, sizeof(dp));
        verdict = solve(0, 0, 0, s);
        cout << "Case " << testCase << ": " << (verdict==0 ? "GOOD" : (verdict==1 ? "BAD" : "MIXED")) << endl;
    }
    return 0;
}