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

double findMean(int a[], int n){
	int sum = 0;
	for (int i = 0; i < n; i++)
		sum += a[i];

	return (double)sum/(double)n;
}

double findMedian(int a[], int n){
	sort(a, a+n);

	if (n % 2 != 0)
	return (double)a[n/2];

	return (double)(a[(n-1)/2] + a[n/2])/2.0;
}

int main(){
	int a[] = { 1, 3, 4, 2, 7, 5, 8, 6 };
	int n = sizeof(a)/sizeof(a[0]);
	cout << "Mean = " << findMean(a, n) << endl;
	cout << "Median = " << findMedian(a, n) << endl;
	return 0;
}
