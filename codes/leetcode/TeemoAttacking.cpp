class Solution {
public:
    int findPoisonedDuration(vector<int>& timeSeries, int duration) {
        int poisoned = 0, till = 0;
        for(int time : timeSeries) {
            poisoned += (time>till) ? duration : (duration-(till-time));
            till = time+duration;
        }
        return poisoned;
    }
};