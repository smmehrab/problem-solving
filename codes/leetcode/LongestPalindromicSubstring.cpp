class Solution {
private:
    string findLPS(string s) { 
        int n = s.size(); 
        if(n == 0 || n==1) return s; 

        string lps="";
        
        // To consider even length palindromes
        // #a#b#a#
        n += (n+1); 

        int length[n]; 
        length[0] = 0; 
        length[1] = 1; 

        int maxLPSLength = 0, maxLPSCenterPosition = 0; 
        int C = 1, R = 2, i, mirror; 
        int start = -1, end = -1, diff = -1; 

        for (i=2; i<n; i++) { 
            // get mirror for i
            mirror = (2*C)-i; 
            length[i] = 0; 
            diff = R - i;

            //If i is within R
            if(diff > 0) 
                length[i] = min(length[mirror], diff); 

            // Attempt to expand palindrome centered at i 
            // For odd positions, we compare characters and 
            // if match then increment LPS Length by 1 
            // For even position, we just increment LPS by 1 
            // without any character comparison 
            while (((i + length[i]) < n && (i - length[i]) > 0) && 
            (((i + length[i] + 1) % 2 == 0) || (s[(i + length[i] + 1)/2] == s[(i - length[i] - 1)/2]))) { 
                length[i]++; 
            }

            // Update maxLPSLength 
            if(length[i] > maxLPSLength) { 
                maxLPSLength = length[i]; 
                maxLPSCenterPosition = i; 
            } 

            // If palindrome centered at i expand beyond R, 
            // adjust C based on expanded palindrome. 
            if (i + length[i] > R) { 
                C = i; 
                R = i + length[i]; 
            } 
        } 

        start = (maxLPSCenterPosition - maxLPSLength)/2; 
        end = start + maxLPSLength - 1; 

        for(i=start; i<=end; i++) 
            lps += s[i];
        return lps;
    } 
    
public:
    string longestPalindrome(string s) {
        return findLPS(s);
    }
};