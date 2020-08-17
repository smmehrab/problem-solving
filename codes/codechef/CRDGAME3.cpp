#include <bits/stdc++.h>
#include <math.h>
using namespace std;

int main()
{
    int testCaseCount, pc, pr, cDigits, rDigits;
    cin >> testCaseCount;
    for (int testCase = 1; testCase <= testCaseCount; testCase++)
    {
        cin >> pc >> pr;
        pc = ceil(pc/9.00);
        pr = ceil(pr/9.00);
        if(pc<pr) cout << 0 << " " << pc << endl;
        else cout << 1 << " " << pr << endl;
    }
    return 0;
}