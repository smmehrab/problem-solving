#include<bits/stdc++.h> 
using namespace std; 

int findNextSparseNumber(int n) { 
    // Decimal to Binary
	vector<bool> binaryLSBtoMSB; 
	while (n) { 
		binaryLSBtoMSB.push_back(n&1); 
		n >>= 1; 
	} 

	binaryLSBtoMSB.push_back(0); 
	int numberOfBits = binaryLSBtoMSB.size();

    // Logic
	int finalizedTill = 0; 
	for (int i=1; i<numberOfBits-1; i++) { 
	    if (binaryLSBtoMSB[i] == 1 && binaryLSBtoMSB[i-1] == 1 && binaryLSBtoMSB[i+1] != 1) { 
            // Finalizing
			binaryLSBtoMSB[i+1] = 1; 
			for (int j=i; j>=finalizedTill; j--) 
				binaryLSBtoMSB[j] = 0; 
			finalizedTill = i+1; 
		} 
	} 

    // Binary to Decimal
	int nextSparseNumber = 0; 
	for (int i=0; i<numberOfBits; i++) 
		nextSparseNumber += binaryLSBtoMSB[i]*(1<<i); 
	return nextSparseNumber; 
} 

int main() { 
    int n;
    while(cin >> n)
	    cout << findNextSparseNumber(n) << endl; 
	return 0; 
} 