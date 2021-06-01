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
    double myPow(double base, int power) {
        return (power>0) ? helper(base, 1LL*power) : 1/helper(base, -1LL*power);
    }
    
    double helper(double base, long long int power){
        if(!power) return 1.00;        
        double result = helper(base, power/2);
        result *= result;
        if(power&1) result *= base;
        return result;
    }
};