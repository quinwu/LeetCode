class Solution {
public:
    int mySqrt(int x) {
        
        if(x <= 1){
            return x;
        }
        
        int l = 0;
        int r = x;
        while( l < r){
            int mid = l + (r - l) / 2;
            
            if(x / mid == mid){
                return mid;
            }
            if(x / mid > mid){
                l = mid + 1;
            }
            else{
                r = mid;
            }
        }
        return r - 1;
    }
};