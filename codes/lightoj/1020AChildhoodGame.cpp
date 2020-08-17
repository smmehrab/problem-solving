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
