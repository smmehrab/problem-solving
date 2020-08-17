class Solution {
public:
    int hIndex(vector<int>& citations) {
        sort(citations.begin(), citations.end());
        int n = citations.size();
        for(int index = 0; index<citations.size(); index++){
            if(citations[index] >= n - index){
                return n-index;
            }
        }
        return 0;
    }
};