class Solution {
public:
    int maxSubArray(vector<int>& numbers) {
        bool atLeastOnePositiveNumber = false;
        int maximumNumber = INT_MIN;
        for(int number : numbers) {
            if(number>=0) {
                atLeastOnePositiveNumber = true;
                break;
            }
            maximumNumber = max(maximumNumber, number);
        }

        if(atLeastOnePositiveNumber) {
            int globalMaximum=numbers[0], currentMaximum=numbers[0], n=numbers.size();
            for(int i=1; i<n; i++) {
                currentMaximum = max(numbers[i], currentMaximum+numbers[i]);
                globalMaximum = max(globalMaximum, currentMaximum);
            }
            return globalMaximum;
        }

        return maximumNumber;
    }
};