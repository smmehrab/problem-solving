class Solution {
public:
    int numPairsDivisibleBy60(vector<int>& durations) {
        vector<int> songs(60, 0);
        int numberOfPairs = 0, remainder;
        for(int duration : durations) {
            remainder = duration % 60;
            numberOfPairs += songs[(60-remainder)%60];
            songs[remainder]++;
        }
        return numberOfPairs;
    }
};