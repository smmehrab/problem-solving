class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {        
        unordered_map<char, int> frequency;
        int totalTasks = tasks.size(), maximumFrequency=0, tasksWithMaximumFrequency=0;

        for (char task : tasks) 
            frequency[task]++;        

        for(const auto& entry : frequency) 
            maximumFrequency = max(maximumFrequency, entry.second);
        
        for(const auto& entry : frequency)
            if(entry.second == maximumFrequency) 
                tasksWithMaximumFrequency++;

        return max(totalTasks, ((maximumFrequency-1)*(n+1)) + tasksWithMaximumFrequency) ;
    }
};