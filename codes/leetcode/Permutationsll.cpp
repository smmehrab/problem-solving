/*
************************************************
username    :   smmehrab
fullname    :   s.m.mehrabul islam
email       :   mehrab.24csedu.001@gmail.com
institute   :   university of dhaka, bangladesh
session     :   2017-2018
************************************************
*/
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