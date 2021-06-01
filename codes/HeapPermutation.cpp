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

void printArr(int a[],int n)
{
	for (int i=0; i<n; i++)
		cout << a[i] << " ";
	printf("\n");
}

void heapPermutation(int a[], int size, int n)
{
	if (size == 1){
		printArr(a, n);
		return;
	}

	for (int i=0; i<size; i++)
	{
		heapPermutation(a,size-1,n);

		if (size%2==1)
			swap(a[0], a[size-1]);

		else
			swap(a[i], a[size-1]);
	}
}

int main()
{
	int a[] = {1, 2, 3, 4};
	int n = sizeof a/sizeof a[0];
	heapPermutation(a, n, n);
	return 0;
}
