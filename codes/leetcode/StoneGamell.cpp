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
private:
    int n;
    vector<int> remainingStones;
    vector<vector<int>> stonesCollected;

    int minimizeRemainingStones(int i, int m) {
        if(i == n) return 0;
        if((i+2*m) >= n) return remainingStones[i];

        int &ret = stonesCollected[i][m];
        if(ret != -1) return ret;

        int minimizedRemainingStones = INT_MAX;
        for(int x=1; x<=2*m; x++) minimizedRemainingStones = min(minimizedRemainingStones, minimizeRemainingStones(i+x, max(m, x)));

        return ret = remainingStones[i]-minimizedRemainingStones;
    }

public:
    int stoneGameII(vector<int>& piles) {
        n = piles.size();
        remainingStones = vector<int>(n, 0);
        stonesCollected = vector<vector<int>>(n, vector<int>(n, -1));

        remainingStones[n-1] = piles[n-1];
        for(int i=n-2; i>=0; i--) remainingStones[i] = remainingStones[i+1] + piles[i];

        return minimizeRemainingStones(0, 1);
    }
};