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
    uint32_t reverseBits(uint32_t n) {
        uint32_t ans=0;
        int bit = 32;
        while(bit--){
            ans= ans << 1;
            if((n&1) ==1){
                ans |= 1;
            }
            n = n >> 1;
        }
        return ans;
    }
};