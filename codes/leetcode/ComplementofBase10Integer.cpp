class Solution {
public:
    int bitwiseComplement(int N) {
        return (N==0) ? 1 : ~N&((1<<((int)log2((double)N)+1))-1);
    }
};