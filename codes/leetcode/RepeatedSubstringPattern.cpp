class Solution {
public:
    bool repeatedSubstringPattern(string input) {
        int inputSize = input.size();
		string substring = "", newString = "";
		for (int i=0; i<inputSize/2; i++) {
			substring += input[i];
			newString = "";
			for (int j=0; j<inputSize/(i+1); j++) newString += substring;
			if(input==newString) return true;
		}
		return false;
    }
};