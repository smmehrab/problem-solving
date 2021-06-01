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

void towerOfHanoi(int n, char source, char destination, char via) {
	if (n == 1) {
		cout << "Move disk 1 from " << source << " to " << destination <<endl;
		return;
	}

	towerOfHanoi(n-1, source, via, destination);
	cout << "Move disk " << n << " from " << source << " to " << destination << endl;
	towerOfHanoi(n-1, via, destination, source);
}

int main() {
	int n;
    cout << "Enter Number of Disks: " << endl;
    cin >> n;

	towerOfHanoi(n, 'A', 'C', 'B');
	return 0;
}