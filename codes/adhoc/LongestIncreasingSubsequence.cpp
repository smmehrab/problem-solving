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

int lis(vector<int>& numbers) {
    if(numbers.empty()) 
        return 0;
     
    vector<int> subsequence;
    for(int number : numbers) {
        if(subsequence.empty())
            subsequence.push_back(number);
        else {
            auto it = lower_bound(subsequence.begin(), subsequence.end(), number);
            if(it == subsequence.end())
                subsequence.push_back(number);
            else
                *it = number;
        }
    }

    return subsequence.size();
}

int main() {
    int n;
    cin >> n;

    vector<int> numbers(n);
    for(int &number : numbers)
        cin >> number;

    cout << lis(numbers) << endl;
	return 0;
}