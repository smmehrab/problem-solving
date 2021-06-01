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
    int findPairs(vector<int>& numbers, int k) {
        sort(numbers.begin(), numbers.end());
        int numberOfPairs=0, n=numbers.size();
        for (int i=1, j=0; i<n; i++){
            if (i<n-1 && numbers[i]==numbers[i+1]) continue;
            while (numbers[i]-numbers[j]>k) j++;
            if(numbers[i]-numbers[j]==k && i!=j) numberOfPairs++;
        }
        return numberOfPairs;
    }
};