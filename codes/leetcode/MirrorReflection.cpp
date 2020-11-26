// extension * p = reflection * q
class Solution {
public:
    int mirrorReflection(int p, int q) {
        int extension = q, reflection = p;
        
        while (!(extension&1) && !(reflection&1)) {
            extension /= 2;
            reflection /= 2;
        }
        if(!(extension&1) && (reflection&1)) return 0;
        else if((extension&1) && (reflection&1)) return 1;
        else if((extension&1) && !(reflection&1)) return 2;
        return -1;
    }
};