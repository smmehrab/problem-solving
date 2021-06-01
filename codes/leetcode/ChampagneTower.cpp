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
    double champagneTower(int poured, int query_row, int query_glass) {
        double dp[110] = {};
        dp[0] = poured;
        for (int row=1; row<=query_row; row++) {
            for (int index=row-1; index>=0; index--) {
				double overflow = (max(dp[index], 1.0)-1.0)/2.0; // Overflowed Amount
                dp[index] = overflow; // Left-Bottom
                dp[index+1] += overflow; // Right-Bottom
            }
        }
        return (dp[query_glass]>=1) ? 1 : dp[query_glass];
    }
};