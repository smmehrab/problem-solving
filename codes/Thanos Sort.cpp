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
#include <algorithm>
using namespace std;

bool isSorted(int a[], int l, int r){
	for (int i = l; i < r - 1; i++) {
		if (a[i] > a[i + 1]) return false;
	}
	return true;
}

int findAns(int a[], int l, int r, int ans) {
	bool sorted = isSorted(a,l,r);


	if (sorted) ans = max(ans, r - l);

	if (r - l >= 2) {
		ans = findAns(a, l, (l + r) >> 1, ans);
		ans = findAns(a, (l + r) >> 1, r, ans);
	}

	return ans;
}

int main(){
    int n, a[10011], ans, i, j, k;
    memset(a, 0, 10011);

	cin >> n;
	for (i = 0; i < n; i++)
        cin >> a[i];

	ans = findAns(a, 0, n, 0);
	cout << ans << endl;
	return 0;
}
