class Solution {
public:
    bool isCharacters(const char& c){
        return ( c >= 'a' && c <= 'z' ) || ( c >= 'A' && c <= 'Z') || ( c >= '0' && c <= '9');
    }
    char lowCase(char& c){
        if( c >= 'A' && c <= 'Z'){
            return c + 32;
        }
        return c;
    }
    bool isPalindrome(string s) {
        vector<char> str;
        for(auto& c:s){
            if(isCharacters(c)){
                str.push_back(lowCase(c));
            }
        }
        
        for(int i = 0,len = str.size() ; i < len / 2 ; i ++){
            if(str[i] != str[len - i - 1]){
                return false;
            }
        }
        return true;
        
    }
};