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
    int t, n, m, answer;
    char x;
    cin >> t;
    while (t--)
    {
        cin >> n >> m;
        answer = 0;
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                cin >> x;
                if(i==n-1 && j==m-1)
                    break;
                else if(i==n-1 && x != 'R')
                    answer++;
                else if(j==m-1 && x != 'D')
                    answer++;
            }
        }
        cout << answer << endl;
    }
    return 0;
}