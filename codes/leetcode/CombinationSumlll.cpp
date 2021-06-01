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
private:
    int limit, totalSum;
    vector<int> valid;
    vector<vector<int>> result;

    void solve(int pos, int sum){
        if(pos==limit) {
            if(sum==totalSum) result.push_back(valid);
            return;
        }
        else if(sum>=totalSum) return; 
        
        int start=1;
        if(valid.size()!=0) start = valid.back()+1; 
        for(int option = start; option <= 9; option++) {
            valid.push_back(option);
            solve(pos+1, sum + option);
            valid.pop_back();
        }
    }

public:
    vector<vector<int>> combinationSum3(int k, int n) {
        limit = k;
        totalSum = n;
        solve(0, 0);
        return result;
    }
};