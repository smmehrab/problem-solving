class Solution {
private:
    string digits;
    int numberOfDigits;
    vector<string> combinations;
    unordered_map<char, string> digitToLetters;

    void dfs(int index, string combination) {
        if (index == numberOfDigits) {
            combinations.push_back(combination);
            return;
        }
        
        string letters = digitToLetters[digits[index]];
        for(char letter : letters)
            dfs(index+1, combination+letter);
    }
    
public:
    vector<string> letterCombinations(string digits) {
        if (digits.size()==0) 
            return {};

        this->digits = digits;
        this->numberOfDigits = digits.size();   
        this->digitToLetters = {
            {'2',"abc"},
            {'3',"def"},
            {'4',"ghi"},
            {'5',"jkl"},
            {'6',"mno"},
            {'7',"pqrs"},
            {'8',"tuv"},
            {'9',"wxyz"}
        };
        
        dfs(0, "");
        return combinations;
    }
};