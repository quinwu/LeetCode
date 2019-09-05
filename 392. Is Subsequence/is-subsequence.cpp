class Solution {
public:
    bool isSubsequence(string s, string t) {
        int n = s.length();
        int m = t.length();
        
        int match = 0;
        int index = 0;
        
        for(int i = 0 ; i < m ; i++){
            if(s[index] == t[i]){
                index++;
                match++;
            }    
        }
        
        if(match == n){
            return true;
        }
        else{
            return false;
        }
    
    }
};