#include <bits/stdc++.h>
using namespace std;

int main () {
    int testCaseCount, n, d;
    cin >> testCaseCount;
    
    for(int testCase=1, numberOfDigits=0, remainder=0; testCase<=testCaseCount; testCase++, numberOfDigits=0, remainder=0) {
        cin >> n >> d;

        do {            
        	remainder = ((remainder*10) + d)%n;
            numberOfDigits++;
        } while(remainder);
        
        cout << "Case " << testCase << ": " << numberOfDigits << endl;
    }
    
    return 0;
}