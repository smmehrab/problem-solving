// The rand7() API is already defined for you.
// int rand7();
// @return a random integer in the range 1 to 7

class Solution {
public:
    int rand10() {
        int row, col, index;
        do {
            row = rand7();
            col = rand7();
            index = ((row-1)*7) + col;
        } while(index>40);
        return (index%10)+1;
    }
};