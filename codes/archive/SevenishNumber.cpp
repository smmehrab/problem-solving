/*
************************************************
username    :   smmehrab
fullname    :   s.m.mehrabul islam
email       :   mehrab.24csedu.001@gmail.com
institute   :   university of dhaka, bangladesh
session     :   2017-2018
************************************************
*/
// Let's define a "sevenish" number to be one 
// which is either a power of 7, or the sum of unique powers of 7. 
// The first few sevenish numbers are 1, 7, 8, 49, and so on. 

// Create an algorithm to find the nth sevenish number.

#include <bits/stdc++.h>
using namespace std;

int findNthSevenish(int n) {
    if(n<1) 
        return -1;
    
    int power = 0, newElement;
    vector<int> sevenishs;
    vector<int> newSevenishs;

    while(sevenishs.size()<n) {
        newElement = pow(7, power);
        newSevenishs.clear();
        newSevenishs.push_back(newElement);

        for(int sevenish : sevenishs) {
            if (sevenishs.size() + newSevenishs.size() == n)
                return newSevenishs.back();
            newSevenishs.push_back(sevenish+newElement);
        }
        
        sevenishs.insert(sevenishs.end(), newSevenishs.begin(), newSevenishs.end());
        power++;
    }

    return sevenishs.back();
}

int main() {
    int n;
    while(cin >> n) {
        cout << n << "th Sevenish Number: " << findNthSevenish(n) << endl;  
    }
    return 0;
}