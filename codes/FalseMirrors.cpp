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

// Find the number of numbers 
// within a range,
// that contains all the digits 0-9,
// at least once

int n, monsters[25];
int dp[25][25][3000][2];
char s[20];

int solve(int shot, int balcony, int hit, int done){

    if(balcony==-1){

    }

    if(balcony==n) return hit;

    // int &ret = dp[shot][balcony][hit][done];
    // if(ret!=-1) return ret;


    int ret=0;
    for(int option = 0; option < n; option++){
        ret += solve(shot+1, option, );
    }

    return ret;
}

int main()
{
    int a, b, answer;
    memset(dp, -1, sizeof(dp));
    cin >> n;
    for(int balcony=0; balcony<n; balcony++)
        cin >> monsters[balcony];
    answer = solve(0, 0, 0, 0);
    cout << answer << endl;
    return 0;
}