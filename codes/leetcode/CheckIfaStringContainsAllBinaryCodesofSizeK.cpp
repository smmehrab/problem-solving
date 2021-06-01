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
    bool hasAllCodes(string s, int k) {
        int n = s.size();
        int numberOfBinaryCodes = 1 << k;
        int numberOfUniqueSubstrings = 0;

        int key = 0;
        int clearKthBit = ~numberOfBinaryCodes; 
        
        bool hashTable[numberOfBinaryCodes]; 
        memset(hashTable, false, sizeof(hashTable));

        for(int i=0; i<n; i++) {                    	    
            key = ((key << 1) & clearKthBit) | (s[i] - '0');       
            if(i >= k-1 && !hashTable[key]) {
                hashTable[key] = true;
                numberOfUniqueSubstrings++;
            }
        }

        return numberOfUniqueSubstrings == numberOfBinaryCodes;
    }
};