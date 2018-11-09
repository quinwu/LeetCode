class Solution {
public:
    int char2int(char c){
        return c-'A' + 1;
    }
    int titleToNumber(string s) {
        int ans =0;
        int len = s.length();
        for(int i = len-1 ; i >= 0 ; i--){
            ans += pow(26,(len-1-i)) * char2int(s[i]);
        }
        return ans;
    }
};