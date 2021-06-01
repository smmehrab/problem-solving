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
    string largestTimeFromDigits(vector<int>& digits) {
        string largestTime = "", time;
        sort(digits.begin(), digits.end());

        do{
            if(((digits[0]==2 && digits[1]<=3) || digits[0]<2) && digits[2]<=5 && digits[3]<=9){
                time = to_string(digits[0]);
                time += to_string(digits[1]);
                time += ':';
                time += to_string(digits[2]); 
                time += to_string(digits[3]);
                largestTime = max(largestTime, time);  
            }
        } while(next_permutation(digits.begin(), digits.end()));

        return time;
    }
};