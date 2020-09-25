class Solution {
public:
    string largestNumber(vector<int>& numbers) {
        if(numbers.size()==0) return "";
        sort(numbers.begin(), numbers.end(), [](const int a, const int b) {
            return ((to_string(a)+to_string(b)) > (to_string(b)+to_string(a)));
        });

        if(numbers[0]==0) return "0";

        string largestNumber;
        for(int number : numbers) largestNumber += to_string(number);
        return largestNumber;
    }
};