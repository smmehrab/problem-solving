#include <bits/stdc++.h>
using namespace std;

long long int nC3(long long int n) {
	if(n<3) return 0;
	return (long long int) (n*(n-1)*(n-2)) / 6;
}

int main() {
    int n, x, frequency[1000001], maxInput = -1;
    long long int multiple[1000001];
    memset(frequency, 0, sizeof(frequency));
    memset(multiple, 0, sizeof(multiple));

    cin >> n;
    for (int i=0; i<n; i++) {
        cin >> x, frequency[x]++;
        maxInput = max(maxInput, x);
    }

	for(int i=1; i<=maxInput; i++) {
		for(int j=i; j<=maxInput; j+=i)
		    multiple[i] += frequency[j];
        // Converting multipleOfIndex into numberOfTripletsHavingGcdEqualToMultipleOfIndex
		multiple[i] = nC3(multiple[i]); 
	}
	
	for(int i=maxInput; i>=1; i--) {
		for(int j=(2*i); j<=maxInput; j+=i)
		    multiple[i] -= multiple[j];
	}
	
    // As we are solving for coprime triplets
	cout << multiple[1] << endl;
    return 0;
}