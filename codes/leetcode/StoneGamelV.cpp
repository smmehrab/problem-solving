/*
************************************************
username    :   smmehrab
fullname    :   s.m.mehrabul islam
email       :   mehrab.24csedu.001@gmail.com
institute   :   university of dhaka, bangladesh
session     :   2017-2018
************************************************
*/
// class Solution {
// private:
//     bool dp[100100];
//     bool solve(int remain) {
//         if(dp[remain]) return dp[remain];
//         for (int i=1; (i*i)<=remain; i++) 
//             if (!solve(remain - (i*i))) 
//                 return dp[remain] = true;
//         return dp[remain];
//     }
    
// public:
//     bool winnerSquareGame(int n) {
//         for(int i=0; i<n+10; i++) dp[i] = false;
//         return solve(n);
//     }
// };

class Solution {
public:
    bool winnerSquareGame(int n) {
        vector<bool> dp(n+1, false);
        for (int i=0; i<=n; i++) {
            if (dp[i]) continue;
            for (int j=1; i+(j*j)<=n; j++) 
                dp[i+(j*j)] = true;
        }
        return dp[n];
    }
};