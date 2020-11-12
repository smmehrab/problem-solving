class Solution {
public:
    vector<vector<int>> permuteUnique(vector<int>& numbers) {
        vector<vector<int>> permutations;
        sort(numbers.begin(), numbers.end()); 
        do { 
            permutations.push_back(numbers);
        } while(next_permutation(numbers.begin(), numbers.end())); 
        return permutations;
    }
};