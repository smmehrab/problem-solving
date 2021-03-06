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
    int bagOfTokensScore(vector<int>& tokens, int power) {
        sort(tokens.begin(), tokens.end());
        int maxScore = 0;
        for(int low = 0, high = tokens.size()-1, score = 0; low <= high;) {
            if(power >= tokens[low]) power -= tokens[low++], maxScore = max(maxScore, ++score);
            else if(score>0) score--, power += tokens[high--];
            else return maxScore;
        }
        return maxScore;
    }
};