class Solution {
public:
    int myAtoi(string str) {
        long ans = 0;
        bool positive = true;
        bool start = false;
        
        for (char c:str){
            if(start && (c > '9' || c < '0')){
                break;
            }
            if (c == ' '){
                continue;
            }
            if( c == '+' || c == '-'){
                if(start){
                    return 0;
                }
                start = true;
                if(c == '-'){
                    positive = false;
                }
            }
            else if ( c > '9' || c < '0'){
                break;
            }
            else if ( c <= '9' || c >= '0'){
                ans = ans * 10 + ( c - '0');
                start = true;
            }

            if( ans > INT_MAX) {
                return positive ? INT_MAX : INT_MIN;
            }
        }
        if (!positive){
            ans = -ans;
        }
        return (int)ans;
        
    }
};