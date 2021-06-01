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
    int t, a, b;
    string s;
    vector<int> ones;

    cin >> t;
    while(t--){
        ones.clear();
        cin >> s;
        int temp = 0;
        int prev = 0;
        for(int i=0; i<s.size(); i++){
            if(s[i]=='1'){
                if(prev == 0){
                    ones.push_back(1);
                    temp++;
                } else{
                    ones[temp-1]++;
                }
                prev = 1;
            } else{
                prev = 0;
            }
        }

        a = 0;
        if(ones.size()>0) {
            // for(int i:ones) cout << i << " ";
            // cout << endl;
            sort(ones.begin(), ones.end());
            reverse(ones.begin(), ones.end());
            for(int i=0; i<ones.size(); i++){
                if(i%2==0) a+= ones[i];
            }
        }
        cout << a << endl;
    }

    return 0;
}