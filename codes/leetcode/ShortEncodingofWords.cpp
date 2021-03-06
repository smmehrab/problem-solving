class Solution {
public:
    int minimumLengthEncoding(vector<string>& words) {        
        for(string& word : words) reverse(begin(word), end(word));
        sort(words.begin(), words.end());
        
        for(string word : words) cout << word << endl;
        
        string s="";
        int n=words.size();
        for(int i=0; i<n; i++) {
            while(i+1<n && words[i] == words[i+1].substr(0, words[i].size())) i++;
            s += string(words[i].rbegin(),words[i].rend()) + "#";
        }
        cout << s << endl;
        return s.size();
    }
};