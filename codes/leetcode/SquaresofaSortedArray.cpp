class Solution {
public:
    vector<int> sortedSquares(vector<int>& numbers) {
        for(int &number : numbers) number *= number;
        sort(numbers.begin(), numbers.end());
        return numbers;
    }
};