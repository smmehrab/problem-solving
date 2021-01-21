class Solution {
public:
    int findDuplicate(vector<int>& numbers) {
        int n = numbers.size();
        for(int i=0; i<n; i++) {
            if(i==numbers[i]-1) continue;
            else if(numbers[numbers[i]-1]==numbers[i] && i!=numbers[i]-1) return numbers[i];
            else swap(numbers[i], numbers[numbers[i]-1]), i--;
        }
        return -1;
    }
};