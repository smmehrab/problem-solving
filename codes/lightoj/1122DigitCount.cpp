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

int testCaseCount;
int m, n, answer;
int s[20];

int solve(int pos, int current){
    if(pos==n) return 1;
    int ret=0;
    for(int option = 0; option < m; option++){
        if(current == -1 || abs(s[option]-current)<=2){
            ret += solve(pos+1, s[option]);
        }
    }
    return ret;
}

int main()
{
    scanf("%d", &testCaseCount);
    for (int testCase = 1; testCase <= testCaseCount; testCase++)
    {
        cin >> m >> n;
        for (int i = 0; i < m; i++)
            cin >> s[i];
        answer = solve(0, -1);
        cout << "Case " << testCase << ": " << answer << endl;
    }
    return 0;
}