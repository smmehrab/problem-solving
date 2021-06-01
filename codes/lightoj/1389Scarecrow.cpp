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
#include <map>
using namespace std;


int main()
{
    int testCaseCount, n, answer, skip;
    string fields;

    scanf("%d", &testCaseCount);
    for (int testCase = 1; testCase <= testCaseCount; testCase++)
    {
        cin >> n;
        cin >> fields;

        answer = 0;
        skip = 0;
        for (char field : fields)
        {
            if(skip==0){
                if(field=='.'){
                    skip=2;
                    answer++;
                }
            } else{
                skip--;
            }
        }

        printf("Case %d: %d\n", testCase, answer);
    }
    return 0;
}