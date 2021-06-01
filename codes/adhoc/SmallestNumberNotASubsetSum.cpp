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

int findSmallestNumberNotASubsetSum(vector<int>& numbers) {
    sort(numbers.begin(), numbers.end());

    int smallestNumber = 1;
    for (int number : numbers) {
        if(number<=smallestNumber)
            smallestNumber += number;
        else 
            break;
    }
    return smallestNumber;
}

int main() {
    int numberOfElements;
    cout << "Enter Number Of Elements:" << endl;
    cin >> numberOfElements;

    vector<int> numbers(numberOfElements);
    cout << "Enter " << numberOfElements << " Numbers:" << endl;
    for(int &number : numbers) 
        cin >> number;

    cout << findSmallestNumberNotASubsetSum(numbers) << endl;
    return 0;
}