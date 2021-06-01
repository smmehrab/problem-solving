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
    int findDuplicate(vector<int>& numbers) {
        int n = numbers.size();
        for(int i=0; i<n; i++) {
            if(i==numbers[i]-1) continue;
            else if(numbers[numbers[i]-1]==numbers[i] && i!=numbers[i]-1) return numbers[i];
            else swap(numbers[i], numbers[numbers[i]-1]), i--;
        }
        return -1;
    }
};