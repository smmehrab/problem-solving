class Solution{
public:
    bool containsNearbyAlmostDuplicate(vector<int> &numbers, int k, int t){
        int n = numbers.size();
        if (n < 2 || k == 0) return false;

        set<long> range;
        for (int start = 0, end=0; end < n; end++){
            if (end-start > k) range.erase(numbers[start++]);

            auto it = range.lower_bound((long) numbers[end] - (long) t);
            if (it != range.end() && (*it) <= ((long) numbers[end] + (long) t)) return true;
            range.insert(numbers[end]);
        }

        return false;
    }
};