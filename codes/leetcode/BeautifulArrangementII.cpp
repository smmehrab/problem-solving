class Solution {
public:
    vector<int> constructArray(int n, int k) {
        vector<int> array(n);
        bool isOdd = (k&1);
        
        int i=0;
        int low=1;
        int high=n;
        
        while(i<k-1) {
            array[i++] = low++;
            array[i++] = high--;
        }
        
        while(i<n) {
            array[i++] = isOdd ? low++ : high--;            
        } 
        
        return array;
    }
};