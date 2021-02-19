class Solution {
public:
    int longestConsecutive(vector<int>& numbers) {
        int consecutive=0, current;
        unordered_set<int> set;
        
        for(int number : numbers) set.insert(number);
        for(int number : set) {
            if(set.find(number-1)==set.end()) {
                current = 1;
                while(set.find(number+current)!=set.end()) current++;
                consecutive = max(consecutive, current);
            }
        }
        
        return consecutive;
    }
};