class Solution {
public:
    int removeDuplicates(vector<int>& numbers) {
        int count = 1;
        for(int i=0; i<numbers.size();) {
            if(i==0 || numbers[i]!=numbers[i-1]) count = 1, i++;
            else if(count==1) count++, i++;
            else numbers.erase(numbers.begin()+i);
        }
        return numbers.size();
    }
};