class Solution {
public:
	vector<int> sequentialDigits(int low, int high) {
		vector<int> result;
        for (int i=1; i<9; i++) {
            int number=i;
            for (int j=i+1; j<10; j++) { 
                number *= 10;
                number += j;
                if (number>=low && number<=high) result.push_back(number);
            }
        }
        sort(result.begin(), result.end()); 
        return result;
	}
};