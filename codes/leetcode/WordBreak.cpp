class Solution {
    bool isBreakable(string remainingString, const unordered_set<string>& dictionary, unordered_map<string, bool>& dp) {
        int len = remainingString.size();
        if (len==0) return true;
        if (dp.find(remainingString) != dp.end()) return dp[remainingString];
        
        for (int i=1; i<=len; ++i) {
            if (dictionary.find(remainingString.substr(0, i)) == dictionary.end()) continue; 
            else if (isBreakable(remainingString.substr(i), dictionary, dp)) {
                dp[remainingString] = true;
                return true;
            }
        }

        dp[remainingString] = false;
        return false;
    }
    
public:
    bool wordBreak(string givenString, vector<string>& wordDictionary) {
        unordered_set<string> dictionary(begin(wordDictionary), end(wordDictionary));
        unordered_map<string, bool> dp;
        return isBreakable(givenString, dictionary, dp);
    }
};