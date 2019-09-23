// Forward declaration of isBadVersion API.
bool isBadVersion(int version);

class Solution {
public:
    int firstBadVersion(int n) {
        if(isBadVersion(1)){
            return 1;
        }
            
        int l = 2;
        int r = n;
        while(l < r){
            int mid = l + (r - l) / 2;
            if(isBadVersion(mid)){
                r = mid;
            }
            else{
                l = mid + 1;
            }
        }
        return r;
    }
};