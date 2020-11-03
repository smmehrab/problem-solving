class Solution {
public:
    int maxPower(string s) {
        int n=s.size();
        if(n==0 || n==1) return 1;
        
        int power = INT_MIN, count = 1;
        for(int i=1; i<n; i++){
            if(s[i]!=s[i-1]) power = max(power, count),  count=1;
            else count++;         
        }
        power = max(power, count);
        return power;
    }
};