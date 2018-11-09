class Solution {
public:
    bool canWinNim(int n) {
        if(n <=3 ){
            return true;
        }
        if (n % 4){
            return true;
        }
        return false;
    }
};