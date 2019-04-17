class Solution {
public:
    string longestPalindrome(string s) {
        string t = "$#";
        for (int i = 0 ; i < s.length() ; i++){
            t += s[i];
            t += "#";
        }
        int p[2010];
        memset(p, 0, sizeof(0));
        int id = 0;
        int mx = 0;
        int resid = 0;
        int resmx = 0;
        for(int i = 1; i < t.size() ; i ++){
            p[i] = mx > i ? min(p[2 * id - i], mx - i) : 1;
            while(t[ i + p[i] ] == t[i - p[i] ]){
                p[i]++;
            }
            
            if( mx < i + p[i]){
                mx = i + p[i];
                id = i;
            }
            if (resmx < p[i]){
                resmx = p[i];
                resid = i;
            }
        }
        return s.substr((resid - resmx) / 2, resmx - 1);
    }
};