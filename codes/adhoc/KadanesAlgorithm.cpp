#include <bits/stdc++.h> 
using namespace std; 

int kadane(vector<int>& a) {
    int localMax = 0, globalMax = 0;
    for(int element : a) {
        localMax = max(element, localMax+element);
        globalMax = max(localMax, globalMax);
    }
    return globalMax;
}

int main () { 
	int numberOfElements;

	cout << "Enter number of elements: " << endl;
	cin >> numberOfElements;
	vector<int> a(numberOfElements, 0);

	cout << "Enter space-separated values of the elements: " << endl;
	for(int &element : a) cin >> element;

    cout << "Sum of the Maximum Sum Subarray is: " << endl;
    cout << kadane(a) << endl;

	return 0; 
} 