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
    int subarraySum(vector<int>& numbers, int k) {
        int answer=0, sum=0;
        map<int, int> hash;

        hash[0]=1;
        for(int number : numbers) {
            sum += number;
            answer += (hash.find(sum-k) != hash.end()) ? hash[sum-k] : 0;
            hash[sum]++;
        }

        return answer;
    }
};