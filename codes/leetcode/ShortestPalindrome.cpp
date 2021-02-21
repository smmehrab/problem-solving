class Solution {
public:
    string shortestPalindrome(string s) {
        int n = s.size();
        
        string sRev(s);
        reverse(sRev.begin(), sRev.end());
        
        string sMerged = s + "#" + sRev;
        int nMerged = sMerged.size();
        
        // KMP
        int k=0;
        vector<int> pi(nMerged, 0);
        for (int i=1; i<nMerged; i++) {
            while (k>0 && sMerged[k] != sMerged[i]) k = pi[k-1];
            if (sMerged[k] == sMerged[i]) k++;
            pi[i] = k;
        }
        
        string palindrome = sRev.substr(0, n-pi[nMerged-1]) + s;
        return palindrome;
    }
};