class Solution {
public:
    bool detectCapitalUse(string word) {
        bool firstflag = true;
        bool flag = true;
        int lowcnt = 0;
        if(word[0] >= 'a' && word[0] <= 'z'){
            firstflag = false;
        }
        for(int i = 0 ; i < word.length() ; i++){
            if(word[i] >= 'a' && word[i] <= 'z'){
                flag = false;
                lowcnt ++;
            }
        }
        
        if(flag){
            return true;
        }
        if(lowcnt == word.length()){
            return true;
        }
        if(firstflag && lowcnt == word.length() -1){
            return true;
        }
        return false;
        
    }
};