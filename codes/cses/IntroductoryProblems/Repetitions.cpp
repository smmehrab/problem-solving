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

int main() {
    string s;
    char previous;
    int count=-1, maxCount=-1;

    cin >> s;
    for(char c : s) {
        if(count == -1 || c!=previous) {
            maxCount = max(count, maxCount);
            count = 1;
            previous = c;
        }
        else if(c == previous) 
            count++;
    }

    maxCount = max(count, maxCount);
    cout << maxCount << endl;
	return 0;
}