/*
************************************************
username    :   smmehrab
fullname    :   s.m.mehrabul islam
email       :   mehrab.24csedu.001@gmail.com
institute   :   university of dhaka, bangladesh
session     :   2017-2018
************************************************
*/
#include<bits/stdc++.h>
using namespace std;

int main(){
    int testCaseCount, x1, y1, x2, y2;
    vector<pair<int, int>> upper, lower; 
    cin >> testCaseCount;
    for(int testCase=1; testCase<=testCaseCount; testCase++){
        cin >> x1 >> y1 >> x2 >> y2;
        if(!lower.size() && !upper.size()){
            lower.push_back({x1, y1});
            upper.push_back({x2, y2});
        } else{
            
        }
    }
    return 0;
}