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
    int testCaseCount, n, w, skip;
    long long int x, Y[60000], answer;

    scanf("%d", &testCaseCount);
    for (int testCase = 1; testCase <= testCaseCount; testCase++)
    {
        scanf("%d %d", &n, &w);
        for (int point = 0; point < n; point++)
        {
            scanf("%lld %lld", &x, &Y[point]);
        }
        sort(Y, Y+n);

        answer=0;
        for(int point = 0; point<n; point++){
            answer++;
            skip = point;
            while(Y[skip]-Y[point]<=w){
                skip++;
            }
            point = skip-1;
        }

        printf("Case %d: %lld\n", testCase, answer);
    }
    return 0;
}