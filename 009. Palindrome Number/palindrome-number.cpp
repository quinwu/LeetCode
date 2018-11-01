class Solution {
public:
    bool isPalindrome(int x) {
        if(x < 0) {
            return false;
        }
        else{
            vector<char> str;
            while(x){
                char c = x % 10 + '0';
                x = x / 10;
                str.push_back(c);
            }
            bool ans = true;
            for(int i = 0 ; i < str.size() /2  ; i++){
                if(str[i] != str[str.size()-1-i]){
                    ans = false;
                    break;
                }
            }
            return ans;
        }
    }
};