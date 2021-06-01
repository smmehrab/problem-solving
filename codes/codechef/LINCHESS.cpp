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
    int testCaseCount, n, k, p[1100], winner, numberOfMoves, minimumNumberOfMoves;
    cin >> testCaseCount;
    for (int testCase = 1; testCase <= testCaseCount; testCase++)
    {
        cin >> n >> k;
        for(int player=1; player<=n; player++)
            cin >> p[player];

        minimumNumberOfMoves = INT_MAX;
        winner = -1;
        for(int player=1; player<=n; player++){
            if(k%p[player]==0){
                numberOfMoves = k/p[player];
                if(numberOfMoves<minimumNumberOfMoves){
                    minimumNumberOfMoves = numberOfMoves;
                    winner = p[player];
                }
            }
        }

        cout << winner << endl;
    }
    return 0;
}
