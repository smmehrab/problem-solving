class Solution {
public:
    int majorityElement(vector<int>& numbers) {
        int majorityElement, frequency=0;
        for(int number : numbers) {
            if(frequency==0) majorityElement = number;
            (number==majorityElement) ? frequency++ : frequency--;
        }
        return majorityElement;
    }
};