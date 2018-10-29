class Solution {
public:
    int lengthOfLastWord(string s) {
        int ans = 0;
        int len = 0;
        for(int i = 0 ; i < s.length() ; i++){
            if(s[i] != ' '){
                len ++;
                if( i == s.length() -1){
                    ans = len;
                }
            }
            else{
                if(len != 0){
                    ans = len;
                    len = 0;
                }
            }
        }
        
        return ans;
    }
};