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