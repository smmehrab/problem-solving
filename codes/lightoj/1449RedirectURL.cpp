#include <bits/stdc++.h>
using namespace std;

int main() {
    int testCaseCount;
    string url;
    cin >> testCaseCount;
    for (int testCase = 1; testCase <= testCaseCount; testCase++) {
        cin >> url;
        int colon = url.find(":");
        string rest = url.substr(colon);
        cout << "Case " << testCase << ": https" << rest << endl;
    }
    return 0;
}