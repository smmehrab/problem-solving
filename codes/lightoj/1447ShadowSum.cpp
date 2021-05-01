#include <bits/stdc++.h>
using namespace std;

int main() {
    int testCaseCount, n;
    cin >> testCaseCount;
    for (int testCase = 1; testCase <= testCaseCount; testCase++) {
        cin >> n;
        map<int, int> indexOf;
        vector<int> numbers(n);
        int i=0, a;
        for(int &number : numbers) {
            cin >> number;
            a = abs(number);
            if(indexOf.find(a)!=indexOf.end()) {
                numbers[indexOf[a]] = 0;
                indexOf[a] = i;
            }
            else {
                indexOf.insert({a, i});
            }
            i++;
        }
        
        int sum=0;
        for(int number : numbers)
            sum += number;

        cout << "Case " << testCase << ": " << sum << endl;
    }
    return 0;
}