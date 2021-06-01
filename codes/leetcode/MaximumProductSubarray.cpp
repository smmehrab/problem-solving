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
    int maxProduct(vector<int>& numbers) {
        int n = numbers.size();
        if(n==0) return -1;

        int maxProd = numbers[0];
        int minProd = numbers[0];
        int ans = numbers[0];
        int choice1, choice2;

        for(int i=1; i<n; i++){
            choice1 = maxProd*numbers[i];
            choice2 = minProd*numbers[i];
            maxProd = max(numbers[i], max(choice1, choice2));
            minProd = min(numbers[i], min(choice1, choice2));
            ans = max(ans, maxProd);
        }

        return ans;
    }
};