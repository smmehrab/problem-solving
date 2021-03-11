class Solution {
public:
    string longestCommonPrefix(vector<string>& words) {
        int n = words.size();
        if (n==0) return "";
        
        sort(words.begin(), words.end(), [](const string& a, const string& b){
            return a.size() < b.size();
        });
        
        string prefix = words[0];
        n = prefix.size();
        for (int i=0; i<n; i++){
            char letter = prefix[i];
            for (string word : words) {
                if (i == word.size() || word[i] != letter) {
                    prefix = words[0].substr(0, i);
                    return prefix;
                }
            }
        }
        return prefix;
    }
};