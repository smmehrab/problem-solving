/*
************************************************
username    :   smmehrab
fullname    :   s.m.mehrabul islam
email       :   mehrab.24csedu.001@gmail.com
institute   :   university of dhaka, bangladesh
session     :   2017-2018
************************************************
*/
// Consider a row of n coins of value v1,v2.......,vn. 
// We play a game against an opponent by alternating turns. 
// In each turn a player selects either the first coin or the last coin from the row, 
// removes it permanently, and receives the value of the coin. 
// Determine the maximum possible amount of money we can definitely win if we move first.

#include <bits/stdc++.h>
using namespace std;

#define MAX 100
int dp[MAX][MAX];

int solve(vector<int> &coins, int start, int end, int sum) {
	if (end == start+1)
		return max(coins[start], coins[end]);

    int &ret = dp[start][end];
	if (ret != -1)
		return ret;

    int choice1 = (sum - solve(coins, start+1, end, sum-coins[start]));
    int choice2 = (sum - solve(coins, start, end-1, sum-coins[end]));
	ret = max(choice1, choice2);

	return ret;
}


int findMaxGain(vector<int> &coins, int numberOfCoins) {
	int sum = 0;
    for(int coin : coins)
        sum += coin;

	memset(dp, -1, sizeof(dp));
	return solve(coins, 0, numberOfCoins-1, sum);
}

int main() {
    int numberOfCoins;
    cin >> numberOfCoins;

    vector<int> coins(numberOfCoins);
    for(int &coin : coins) 
        cin >> coin;

    cout << findMaxGain(coins, numberOfCoins) << endl;  
	return 0;
}
