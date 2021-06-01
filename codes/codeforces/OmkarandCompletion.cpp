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
#include <stdio.h>
#include <math.h>
#include <stdbool.h>
using namespace std;

// Driver Code
int main()
{
    int testCaseCount;
    int testCase;
    int n;
    scanf("%d", &testCaseCount);
    for (testCase = 1; testCase <= testCaseCount; testCase++)
    {
        scanf("%d", &n);
        for(int i=0; i<n; i++){
            cout << 1;
            if(i!=n-1)
                cout << " ";
        }
        cout << endl;
    }
    return 0;
}