class Solution {
public:
    int minMoves2(vector<int>& numbers) {
        sort(numbers.begin(), numbers.end());
        
        int n = numbers.size();
        int median = numbers[(n/2)];
        int numberOfMoves = 0;
        
        for(int number : numbers) 
            numberOfMoves += abs(median-number);
        
        return numberOfMoves;
    }
};