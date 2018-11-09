class Solution {
public:
    bool isHappy(int n) {
        if(n == 1){
            return true;
        }
        if(n == 4){
            return false;
        }
        int num = 0;
        int t = n;
        while(t){
            int mod = t % 10;
            num += mod*mod;
            t /= 10;
        }
        if(num == n){
            return false;
        }
        return isHappy(num);
    }
};