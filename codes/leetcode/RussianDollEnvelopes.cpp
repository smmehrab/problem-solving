class Solution {    
public:
    int maxEnvelopes(vector<vector<int>>& envelopes) {
        sort(envelopes.begin(), envelopes.end(), [](const vector<int>& a, const vector<int>& b) {
            return (a[0]==b[0]) ? (a[1]>b[1]) : (a[0]<b[0]);                                                                 
        });
        
        int height, index;
        vector<int> russianDoll;
        for (vector<int>& envelope : envelopes) {
            height = envelope[1];
            index = lower_bound(russianDoll.begin(), russianDoll.end(), height) - russianDoll.begin();
            if (index == russianDoll.size()) 
                russianDoll.push_back(height);
            russianDoll[index] = height;
        }
        return russianDoll.size();
    }
};