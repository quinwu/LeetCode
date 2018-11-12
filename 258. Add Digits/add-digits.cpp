class Solution {
public:
    int addDigits(int num) {
        if(!num){
            return 0;
        }
        int ans = num % 9;
        if(ans){
            return ans;
        }
        else{
            return 9;
        }
    }
};