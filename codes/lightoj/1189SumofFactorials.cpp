#include <bits/stdc++.h>
using namespace std;

vector<long long int> precalculate() {
    vector<long long int> factorial;
    factorial.push_back(1);
    for(long long int i=1; i<=20; i++) 
        factorial.push_back(i*factorial[i-1]);
    return factorial;
}

int main() {
    int testCaseCount;
    cin >> testCaseCount;

    vector<long long int> factorial = precalculate();
    long long int n;
    vector<long long int> summation;
    string output;

    for (int testCase = 1; testCase <= testCaseCount; testCase++) {
        cin >> n;
        summation.clear();
        output = "impossible";

        for(int i=20; i>=0; i--) {
            if(factorial[i]<=n) {
                n-=factorial[i];
                summation.push_back(i);
            }
        }
        
        if(n==0) {
            output = "";
            reverse(summation.begin(), summation.end());
            for(long long  int number : summation) 
                output += to_string(number) + "!+";
            if (!output.empty()) 
                output.erase(output.size()-1);
        }

        cout << "Case " << testCase << ": " << output << endl;
    }
    return 0;
}