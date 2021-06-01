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
    bool find132pattern(vector<int>& numbers) {
        // variables named according to 132
        
        int n = numbers.size();
        reverse(numbers.begin(), numbers.end());
        
        stack<int> twos;
        int two = INT_MIN;
        
        for(int one : numbers){
            if(one<two) return true;
            while(!twos.empty() && twos.top()<one) {
                two = twos.top();
                twos.pop();
            }
            twos.push(one);
        }
        return false;
    }
};