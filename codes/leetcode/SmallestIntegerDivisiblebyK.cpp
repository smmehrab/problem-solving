class Solution {
public:
    int smallestRepunitDivByK(int k) {
        int n = 0;
        for (int len=1; len<=k+1; len++) {
            n = ((n*10)+1)%k;
            if (n==0) return len;  
        }
        return -1;
    }
};