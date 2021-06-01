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

int main(){
    char s[4][105];
    int len[4],i,j, c =0, ans;
	bool greatest = 1, least = 1;


	for (i = 0; i < 4; i++){
        cin >> s[i];
		len[i] = strlen(s[i]) - 2;
	}

	for (i = 0; i < 4; i++){
		greatest = 1;
		least = 1;

		for (j = 0; j < 4; j++){
			if (i == j)
                continue;
			if (len[i] < 2 * len[j])
				greatest = 0;
			if (len[i] * 2 > len[j])
                least = 0;
		}

		if (greatest || least){
			c++;
			ans = i;
		}
	}

	char a = 'A' + ans;
	if (c == 1)
		cout << a << endl;

	else
		cout << "C" << endl;

	return 0;
}
