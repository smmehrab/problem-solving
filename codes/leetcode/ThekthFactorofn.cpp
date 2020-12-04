class Solution {
public:
    int kthFactor(int n, int k) {
        int nth=0;
        for(int i=1; i<=n/2; i++) {
            if(n%i==0){
                if(++nth==k) return i;
            }
        }
        return (++nth==k) ? n : -1; 
    }
};