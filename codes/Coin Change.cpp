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

int getCoinCount(int coins[], int numberOfCoins, int change){

	int i, j, including, excluding;
	int table[change + 1][numberOfCoins];

	for (i = 0; i < numberOfCoins; i++)
		table[0][i] = 1;

	for (i = 1; i < change + 1; i++){
		for (j = 0; j < numberOfCoins; j++){
			including = (i >= coins[j]) ? table[i - coins[j]][j] : 0;
			excluding = (j >= 1) ? table[i][j - 1] : 0;

			table[i][j] = including + excluding;
		}
	}
	return table[change][numberOfCoins - 1];
}

int main(){
	int coins[] = {1, 2, 3};
	int numberOfCoins = sizeof(coins)/sizeof(coins[0]);
	int change = 4;
	cout << getCoinCount(coins, numberOfCoins, change);
	return 0;
}
