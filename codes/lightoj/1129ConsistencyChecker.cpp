#include <bits/stdc++.h>
using namespace std;

bool startsWith(std::string mainStr, std::string toMatch)
{
    if(mainStr.find(toMatch) == 0)
        return true;
    else
        return false;
}

int main()
{
    int testCaseCount, n;
    string number[100000];
    bool answer;

    scanf("%d", &testCaseCount);
    for (int testCase = 1; testCase <= testCaseCount; testCase++)
    {
        scanf("%d", &n);

        answer = true;
        for (int i = 0; i < n; i++)
        {
            cin >> number[i];
        }

        sort(number, number+n); 

        for (int i = 1; i < n; i++)
        {
            if(startsWith(number[i], number[i-1])){
                answer=false;
                break;
            }
        }

        if(answer){
            printf("Case %d: YES\n", testCase);
        }
        else{
            printf("Case %d: NO\n", testCase);
        }
    }
    return 0;
}