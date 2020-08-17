#include <bits/stdc++.h>
using namespace std;

int main()
{
    int testCaseCount, h, p, didChefWin;
    cin >> testCaseCount;
    for (int testCase = 1; testCase <= testCaseCount; testCase++)
    {
        didChefWin = 1;
        cin >> h >> p;

        while(h!=0 && p!=0){
            h -= p;
            p/=2;
        }

        if(h>0) didChefWin = 0;
        cout << didChefWin << endl;
    }
    return 0;
}
