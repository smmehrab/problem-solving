/*
************************************************
username    :   smmehrab
fullname    :   s.m.mehrabul islam
email       :   mehrab.24csedu.001@gmail.com
institute   :   university of dhaka, bangladesh
session     :   2017-2018
************************************************
*/
class Solution {
public:
    int distributeCandies(vector<int>& types) {
        sort(types.begin(), types.end());
        int n = types.size(), m = 0;
        for(int i=0; i<n; i++) {
            if(i==0 || types[i]!=types[i-1]) m++;
        }
        return min((n/2), m);
    }
};