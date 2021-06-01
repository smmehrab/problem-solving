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
    vector<int> majorityElement(vector<int>& numbers) {
        int majorityElement1=INT_MIN, majorityElement2=INT_MIN, frequency1=0, frequency2=0, threshold = numbers.size()/3;
        vector<int> majorityElements;

        for(int number : numbers) {
            if(number==majorityElement1) frequency1++;
            else if(number==majorityElement2) frequency2++;
            else if(frequency1==0){
                majorityElement1 = number;
                frequency1++;
            } 
            else if(frequency2==0) {
                majorityElement2 = number;
                frequency2++;
            }
            else{
                frequency1--;
                frequency2--;
            }
        }
        
        frequency1=0;
        frequency2=0;
        for(int number : numbers){
            if(number == majorityElement1) frequency1++;
            else if(number == majorityElement2) frequency2++;
        }
        
        if(frequency1 > threshold) majorityElements.push_back(majorityElement1);
        if(frequency2 > threshold) majorityElements.push_back(majorityElement2);
        return majorityElements;
    }
};