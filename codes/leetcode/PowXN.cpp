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