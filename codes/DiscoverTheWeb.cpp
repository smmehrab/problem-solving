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
#include <stack>
using namespace std;

int main()
{
    int testCaseCount;
    scanf("%d", &testCaseCount);
    for (int testCase = 1; testCase <= testCaseCount; testCase++)
    {
        printf("Case %d:\n", testCase);

        stack<string> backwardStack, forwardStack;
        backwardStack.push("http://www.lightoj.com/");

        while (true)
        {
            string command, url;
            cin >> command;

            if (command == "VISIT")
            {
                cin >> url;
                backwardStack.push(url);
                cout << backwardStack.top() << endl;
                while (!forwardStack.empty())
                {
                    forwardStack.pop();
                }
            }

            else if (command == "BACK")
            {
                if (backwardStack.size() <= 1){
                    cout << "Ignored" << endl;
                }
                else
                {
                    forwardStack.push(backwardStack.top());
                    backwardStack.pop();
                    cout << backwardStack.top() << endl;
                }
            }
            else if (command == "FORWARD")
            {
                if (forwardStack.empty()){
                    cout << "Ignored" << endl;
                }
                else
                {
                    backwardStack.push(forwardStack.top());
                    forwardStack.pop();
                    cout << backwardStack.top() << endl;
                }
            }
            else{
                break;
            }
        }
    }
}