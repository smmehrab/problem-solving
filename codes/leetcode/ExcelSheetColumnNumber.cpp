class Solution {
public:
    int titleToNumber(string s) {
        int answer=0;
        for(char letter : s){
            answer *= 26; 
            answer += letter-'A'+1;
        }
        return answer;
    }
};