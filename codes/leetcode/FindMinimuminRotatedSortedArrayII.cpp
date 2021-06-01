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
    int findMin(vector<int>& numbers) {
        int minNumber;
        for(int index=0; index<numbers.size(); index++){
            if(index==0){
                minNumber = numbers[index];
            } else if(numbers[index]<minNumber){
                minNumber = numbers[index];
            }
        }
        return minNumber;
    }
};