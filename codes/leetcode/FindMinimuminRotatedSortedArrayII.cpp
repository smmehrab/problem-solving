class Solution {
public:
    int findMin(vector<int>& numbers) {
        int minNumber;
        for(int index=0; index<numbers.size(); index++){
            if(index==0){
                minNumber = numbers[index];
            } else if(numbers[index]<minNumber){
                minNumber = numbers[index];
            }
        }
        return minNumber;
    }
};