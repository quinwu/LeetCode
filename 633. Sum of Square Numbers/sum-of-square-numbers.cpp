class Solution {
public:
    bool judgeSquareSum(int c) {
        for(int i = 0 ; i <= sqrt(c) ; i++){
            int frac = sqrt(c - i*i);
            if (frac * frac == c - i*i){
                return true;
            }
        }
        return false;
    }
};