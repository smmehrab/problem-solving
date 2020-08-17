class Solution {
public:
    vector<int> singleNumber(vector<int> numbers) {
        int x, m, r1, r2;

        x = 0;
        for (int number : numbers) {
            x ^= number;
        }

        m = -x & x;
        r1 = 0;
        r2 = 0;
        for (int number : numbers) {
            if ((number & m) == 0)
                r1 ^= number;
            else 
                r2 ^= number;
        }

        return vector<int> {r1, r2};
    }
};