class Solution {
private:
    int n;
    string s;
    vector<vector<string>> allPartitionings;
    vector<string> partitioning;
    vector<vector<bool>> dp;

    void solve(int i) {
        if(i==n){
            allPartitionings.push_back(partitioning);
            return ;
        }
        
        for(int j=i; j<n; ++j){
            if(s[i] == s[j] && (j-i<=2 || dp[i+1][j-1])){
                dp[i][j] = true;
                partitioning.push_back(s.substr(i, j-i+1));
                solve(j+1);
                partitioning.pop_back();
            }
        }
    }

public:
    vector<vector<string>> partition(string s) {
        this->s = s;
        this->n = s.size();
        this->dp = vector(n, vector<bool>(n, false));
        if(n!=0) solve(0);
        return allPartitionings;
    }
};