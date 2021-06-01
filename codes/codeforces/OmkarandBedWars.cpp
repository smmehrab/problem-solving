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
    int t, n;
    string s;
    cin >> t;
    while (t--)
    {
        cin >> n;
        cin >> s;

        int consecutive = 0, ans =0;
        while (s.size() && s[0] == s.back())
        {
            consecutive++;
            s.pop_back();
        }

        if (s.empty())
        {
            if (consecutive > 3) ans = (consecutive + 2) / 3;
            else ans = consecutive/3;
        } 
        else{
            s.push_back('$');
            for (int i = 0; i<s.size()-1; i++)
            {
                consecutive++;
                if (s[i] != s[i+1])
                {
                    ans += consecutive / 3;
                    consecutive = 0;
                }
            }
        }

        cout << ans << endl;
    }
    return 0;
}