#include<bits/stdc++.h>
using namespace std;

long long int solve(long long int sum) {
    long double c = sum;
    return (long long int) (-1.0 + sqrt(1+(4*c)))/2.00;
}

long long int nC2(long long int n) {
    return (n*(n-1)) / 2;
}

int main() {
    int testCases;
    long long int n, pivot, sum, result;
    cin >> testCases;
    while (testCases--) {
        cin >> n;
        result = 0;
        
		sum = (n*(n+1))/2;
        if (sum%2==0) {
	        pivot = solve(sum);
	        result += n-pivot;
            if (2 * ((pivot*pivot) + pivot) == ((n*n) + n)) result += nC2(pivot) + nC2(n-pivot);
        }
      
        cout << result << endl;
    }

    return 0;
}