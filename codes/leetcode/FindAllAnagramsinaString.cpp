class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        vector<int> startingIndices;
        unordered_map<char,int> frequency;
        for(char c : p) frequency[c]++;
        
        int left=0, right=0, window=p.size(), boundary=s.size(), pSize=p.size();
        while(right<s.size()){
            if(--frequency[s[right++]]>=0) window--;
            while(left<right && window==0){
                if(right-left==pSize) startingIndices.push_back(left);
                if(++frequency[s[left++]]>0) window++;
            }
        }
        return startingIndices;
    }
};