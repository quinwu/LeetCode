class Solution {
public:
    char int2char(int n){
        return 'A' + n;
    }
    string convertToTitle(int n) {
        int t = n;
        string str = "";
        while(t){
            t--;
            char c = int2char(t%26);
            t /= 26;
            str =  c + str;
        }
        return str;
    }
};