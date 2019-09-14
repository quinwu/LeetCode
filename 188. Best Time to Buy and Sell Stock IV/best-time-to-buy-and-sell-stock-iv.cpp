class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
        int n = prices.size();
        
        if(n == 0){
            return 0;
        }
        
        if( k >= n / 2){
            int maxPro = 0;
            for(int i = 1 ; i < n ; i++){
                if(prices[i] > prices[i-1]){
                    maxPro += prices[i] - prices[i-1];
                }
            }
            return maxPro;
        }
        
        int dp[2][n];
        memset(dp,0,sizeof(dp));
        dp[0][0] = 0;
        
        for(int kk = 1; kk <= k ; kk ++){
            int tmpMax = dp[0][0] - prices[0];
            for(int i = 1 ; i < n ; i++){
                dp[1][i] = max(dp[1][i-1], prices[i] + tmpMax);
                tmpMax = max(tmpMax, dp[0][i] - prices[i]);
                dp[0][i] = dp[1][i];
            }
        }
        
        return dp[0][n-1];
        
    }
};