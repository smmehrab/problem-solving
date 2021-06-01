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

int main()
{
    long long int testCaseCount, r, b, g, w, oddCount, evenCount, ifOdd, total, ifChangeable, answer;
    cin >> testCaseCount;
    for (long long int testCase = 1; testCase <= testCaseCount; testCase++)
    {
        cin >> r >> g >> b >> w;
        answer = 0;
        oddCount = 0;
        evenCount = 0;
        ifChangeable = 0;

        if(r==0 && g==0 && b==0)
            answer = 1;
        else {
            if(r!=0 && g!=0 && b!=0) ifChangeable = 1;

            total = r + g + b + w;
            ifOdd = total % 2;
            if(r%2==0) evenCount++;
            if(g%2==0) evenCount++;
            if(b%2==0) evenCount++;
            if(w%2==0) evenCount++;
            oddCount = 4 - evenCount;

            if(ifOdd==1){
                if(oddCount == 1 || (ifChangeable==1 && evenCount==1)) answer = 1;
                else answer = 0;
            } else{
                if(oddCount == 0 || (ifChangeable==1 && evenCount==0)) answer = 1;
                else answer = 0;
            }
        }
        
        if(answer == 1) cout << "Yes" << endl;
        else cout << "No" << endl;
    }
    return 0;
}