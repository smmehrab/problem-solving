class Solution {
public:
    int rob(vector<int>& houses) {
        int currentMax, previousMax, newMax, ans;
        int n = houses.size();
        
        if(n==0) return 0;
        else if(n==1) return houses[0];
        
        currentMax = 0;
        previousMax = 0;
        for(int i=0; i<n-1; i++){
            newMax = max(currentMax, previousMax +  houses[i]);
            previousMax = currentMax;
            currentMax = newMax;
        }
        ans = currentMax;

        currentMax = 0;
        previousMax = 0;
        for(int i=1; i<n; i++){
            newMax = max(currentMax, previousMax +  houses[i]);
            previousMax = currentMax;
            currentMax = newMax;
        }
        ans = max(ans, currentMax);
        
        return ans;
    }
};