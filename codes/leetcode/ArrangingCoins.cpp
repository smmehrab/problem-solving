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
    int arrangeCoins(int n) {
        long long int low=0, high=n, mid, sum;
        while (low <= high) {
            mid = low + (high-low) / 2;
            sum = (mid * (mid + 1)) / 2;
            if (sum == n) 
                return (int) mid;
            else if (sum > n) 
                high = mid-1;
            else 
                low = mid+1;
        }
        return (int) high;
    }
};