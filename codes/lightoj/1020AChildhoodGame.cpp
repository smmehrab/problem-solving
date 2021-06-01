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
#include <string>
using namespace std;

int main()
{
    int testCaseCount, numberOfMarbles;
    string initiator, winner;

    scanf("%d", &testCaseCount);
    for (int testCase = 1; testCase <= testCaseCount; testCase++)
    {
        cin >> numberOfMarbles >> initiator;
        if(initiator=="Alice"){
            if(numberOfMarbles%3==1){
                winner = "Bob";
            }else{
                winner = "Alice";
            }
        }
        else{
            if(numberOfMarbles%3==0){
                winner = "Alice";
            }else{
                winner = "Bob";
            }
        }

        cout << "Case " << testCase << ": " << winner << endl;
    }
    return 0;
}
