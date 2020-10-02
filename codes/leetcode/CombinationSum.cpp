class Solution {
private:
    vector<vector<int>> combinations;
    vector<int> combination;
    vector<int> candidates;
    int target, numberOfCandidates;

    void findCombinations(int index, int sum) {
        if(index == numberOfCandidates || sum > target) return;
        
        if(sum == target) { 
            combinations.push_back(combination);
            return;
        }
        
        combination.push_back(candidates[index]);
        findCombinations(index, sum+candidates[index]);
        combination.pop_back();
		findCombinations(index+1, sum);
    }

public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) { 
        this->candidates = candidates;
        this->target = target;
        this->numberOfCandidates = candidates.size();
        findCombinations(0, 0);
        return combinations;
    }
};