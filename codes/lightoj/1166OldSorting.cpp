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
    int testCaseCount, n, input[200000], answer, temp;
    bool changed;

    scanf("%d", &testCaseCount);
    for (int testCase = 1; testCase <= testCaseCount; testCase++)
    {
        scanf("%d", &n);
        answer = 0;

        for (int i = 1; i <= n; i++)
        {
            scanf("%d", &input[i]);
        }

        do{
            changed=false;
            for (int i = 1; i <= n; i++)
            {
                if (i != input[i])
                {
                    changed=true;
                    temp = input[i];
                    input[i] = input[temp];
                    input[temp] = temp;
                    answer++;
                }
            }
        }while(changed);

        printf("Case %d: %d\n", testCase, answer);
    }
    return 0;
}
