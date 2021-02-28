class Solution {
public:
    bool isPalindrome(int x) {
        long long int y=0, digit, tempX=x;
        if(x<0) return false;
        if(x<10) return true;
        
        while(tempX){
            digit = tempX%10;
            y *= 10;
            y += digit;
            tempX /= 10;
        }

        return x == y;
    }
};