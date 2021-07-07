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

int findLongestDistinctSubarray(vector<int> a, int n) { 
	unordered_map<int, int> indexOf; 
	int len = 0; 
	for (int i=0, validStart=0; i<n; i++) { 
		validStart = max(indexOf[a[i]], validStart); 
		len = max(len, i-validStart+1); 
		indexOf[a[i]] = i+1;
	} 
	return len; 
} 

int main () { 
	int numberOfElements, element, start, end;
	vector<int> input;

	cout << "Enter number of elements: " << endl;
	cin >> numberOfElements;
	cout << "Enter space-separated values of the elements: " << endl;
	for(int i=0; i<numberOfElements; i++) {
		cin >> element;
		input.push_back(element);
	}

	cout << "The Length of the Longest Subarray with all Distinct Elements is:" << endl;
	cout << findLongestDistinctSubarray(input, numberOfElements) << endl;
	return 0; 
} 