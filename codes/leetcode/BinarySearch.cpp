class Solution {
public:
    int search(vector<int>& sorted, int target) {
        return binary_search(sorted.begin(), sorted.end(), target) ? lower_bound(sorted.begin(), sorted.end(), target) - sorted.begin() : -1;
    }
};