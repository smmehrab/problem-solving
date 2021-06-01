/*
************************************************
username    :   smmehrab
fullname    :   s.m.mehrabul islam
email       :   mehrab.24csedu.001@gmail.com
institute   :   university of dhaka, bangladesh
session     :   2017-2018
************************************************
*/
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