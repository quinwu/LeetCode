class Solution {
public:
    bool backspaceCompare(string S, string T) {
        int len_S = S.length();
        int len_T = T.length();
        while(true){
            for(int backspace = 0; len_S && (backspace || S[len_S-1] == '#'); len_S --){
                backspace += S[len_S-1] == '#' ? 1 : -1;
            }
            
            for(int backspace = 0; len_T && (backspace || T[len_T-1] == '#'); len_T --){
                backspace += T[len_T-1] == '#' ? 1 : -1;
            }
            
            if(len_S  && len_T  && S[len_S-1] == T[len_T-1]){
                len_S --;
                len_T --;
            }
            else{      
                return !len_S  && !len_T ;
            }
        }
    }
};