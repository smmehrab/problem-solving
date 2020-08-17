class Solution {
public:
    int longestPalindrome(string s) {
        int result = 0;
        vector<int> characterCount(256, 0); 
        for (char c : s) {
            characterCount[c]++;
            if (characterCount[c] % 2 == 0) result += 2; 
        }
        if (s.size() > result) result++;
        return result;
    }
};