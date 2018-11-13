class Solution {
public:
    int hammingDistance(int x, int y) {
        int diff = 0 ;
        int bit = 1;
        for(int i = 0 ; i < 31 ; i++){
            if (( x & bit ) != ( y & bit )){
                diff++;
            }
            bit <<= 1;
        }
        return diff;
    }
};