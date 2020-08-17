class Solution {
public:
    int firstMissingPositive(vector<int> input)
    {
        for(int index = 0; index < input.size(); index++) {
            while(input[index] >= 1 && input[index] <= input.size() && input[index] != input[input[index]-1]){
                swap(input[index], input[input[index] - 1]);
            }
        }
        
        for(int index = 0; index < input.size(); index++){
            if(input[index] != index + 1){
                return index + 1;
            }
        }
        
        return input.size() + 1;
    }
};