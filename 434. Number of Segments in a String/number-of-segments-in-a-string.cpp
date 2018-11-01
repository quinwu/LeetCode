class Solution {
public:
    int countSegments(string s) {
        bool is_word = false;
        int ans = 0;
        for (char ss: s){
            if (ss != ' '){
                if(is_word == false){
                    ans ++;
                    is_word = true;
                }
            }
            else{
                is_word = false;
            }
        }
        return ans;
    }
};