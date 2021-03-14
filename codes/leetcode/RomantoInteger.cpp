class Solution {
private:
    int decode(char c) {
        switch(c) {
            case 'I': 
                return 1;
            case 'V': 
                return 5;
            case 'X':
                return 10;
            case 'L':
                return 50;
            case 'C':
                return 100;
            case 'D':
                return 500;
            case 'M':
                return 1000;
            default:
                return 0;
        }
    }
    
public:
    int romanToInt(string roman) {        
        int n = roman.size();
        int decimal = 0;
        int current, next;

        for(int i=0; i<n; i++) {
            if(i==0)
                current = decode(roman[i]);
            next = decode(roman[i+1]);
            if (current<next) decimal -= current;
            else decimal += current;
            current = next;
        }
        
        return decimal;
    }
};