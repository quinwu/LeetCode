class Solution {
public:
    int numJewelsInStones(string J, string S) {
        bool vis[100];
        memset(vis,0,sizeof(vis));
        
        for (int i = 0 ; i < J.length() ; i++){
            vis[J[i] - 'A' ] = 1;
        }
        int ans = 0;
        for (int i = 0 ; i < S.length() ; i++){
            if  (vis[S[i] - 'A']){
                ans ++;
            }
        }
        return ans;
    }
};