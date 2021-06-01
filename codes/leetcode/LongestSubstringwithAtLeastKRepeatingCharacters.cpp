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
    int solve(string &s, int start, int end, int k) {
        if (end<k) return 0;

        int frequency[26] = {0};
        for (int i=start; i<end; i++) frequency[s[i]-'a']++;

        for (int mid=start; mid<end; mid++) {
            if (frequency[s[mid]-'a'] >= k) continue;
            int midNext = mid+1;
            while (midNext<end && frequency[s[midNext]-'a']<k) midNext++;
            return max(solve(s, start, mid, k), solve(s, midNext, end, k));
        }
        return (end-start);
    }

public:
    int longestSubstring(string s, int k) {
        return solve(s, 0, s.size(), k);
    }
};