class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        int intervalCount = intervals.size();
		if (intervalCount == 0) return {newInterval};

		vector<vector<int>> result;
        int index=0;

        // Before
        while (index<intervalCount && newInterval[0]>intervals[index][1]) result.push_back(intervals[index++]); 

        // Overlapped
		result.push_back(newInterval); 
		int overlappedIndex = result.size() - 1;
        if (index<intervalCount) result[overlappedIndex][0] = min(result[overlappedIndex][0], intervals[index][0]);      
        while (index<intervalCount && intervals[index][0] <= result[overlappedIndex][1]) result[overlappedIndex][1] = max(result[overlappedIndex][1], intervals[index++][1]);        

        // After
        while (index<intervalCount) result.push_back(intervals[index++]);
        
        return result;
    }
};