class Solution {
private:
    int n;
    vector<int> shuffled;
    vector<int> original;

    int randRange(int min, int max) {
        return rand()%(max-min+1) + min;
    }

public:
    Solution(vector<int>& input) {
        original = input;
        shuffled = input;
        n = input.size();
    }
    
    /** Resets the array to its original configuration and return it. */
    vector<int> reset() {
        shuffled = original;
        return original;  
    }
    
    /** Returns a random shuffling of the array. */
    vector<int> shuffle() {
        for (int i=0; i<n; i++) swap(shuffled[i], shuffled[randRange(i, n-1)]);
        return shuffled;
    }    
};