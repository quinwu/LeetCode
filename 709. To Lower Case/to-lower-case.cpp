class Solution {
public:
    
    char toLower(char c){
        if(c >= 'A' && c <= 'Z'){
            return c + 32;
        }
        return c;
    }
    
    string toLowerCase(string str) {
        for(int i = 0 ; i < str.length(); i++){
            str[i] = toLower(str[i]);
        }
        return str;
    }
};