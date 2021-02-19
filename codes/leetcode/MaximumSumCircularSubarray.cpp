class Solution {
private:
    int kadane(vector<int>& a) {
        int localMax = 0, globalMax = 0;
        for(int element : a) {
            localMax = max(element, localMax+element);
            globalMax = max(localMax, globalMax);
        }
        return globalMax;
    }

public:
    int maxSubarraySumCircular(vector<int>& a) {
        int totalSum = 0, maxNegative=INT_MIN, maxPositive = 0;
        int simpleKadane = kadane(a), wrapAroundKadane, answer;
        bool ifAllNegative = true;

        for(int& element : a) {
            if(element>0) ifAllNegative = false, maxPositive = max(maxPositive, element);
            else maxNegative = max(maxNegative, element);
            totalSum += element;
            element *= -1;
        }
        wrapAroundKadane = totalSum - (-kadane(a));

        answer = ifAllNegative ? maxNegative : max(simpleKadane, max(maxPositive, wrapAroundKadane));
        return answer;
    }
};