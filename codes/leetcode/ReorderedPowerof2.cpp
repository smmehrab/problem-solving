class Solution {
public:
    bool reorderedPowerOf2(int n) {
        string nString = to_string(n);
        sort(nString.begin(), nString.end());
        
        for (int i=0; i<30; i++) {
            string powerOfTwo = to_string(1<<i);
            sort(powerOfTwo.begin(), powerOfTwo.end());
            if (nString == powerOfTwo) 
                return true;
        }
        return false;
    }
};