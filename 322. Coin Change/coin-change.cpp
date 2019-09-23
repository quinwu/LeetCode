class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        
        int n = coins.size();
        if(n == 0){
            return -1;
        }
        
        vector<int> cost;
        vector<int> weight;
        
        for(int i = 0 ; i < n ; i++){
            int k = 1;
            while(k*coins[i] <= amount){
                cost.push_back(k * coins[i]);
                weight.push_back(k);
                k *= 2;
            }
            
        }
        
        vector<int> dp(amount+2, amount+1);
        dp[0] = 0;
        
        for(int i = 1 ; i <= cost.size() ; i++){
            for(int j = cost[i-1] ; j <= amount ; j++){
                dp[j] = min(dp[j], dp[j - cost[i-1]] + weight[i-1]);
            }
        }
        
        return (dp[amount] > amount ? -1 : dp[amount]);
        
    }
};