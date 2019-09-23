class Solution {
public:
    bool canPartition(vector<int>& nums) {
        
        if(nums.size() == 0){
            return false;
        }
        
        
        int n = nums.size();
        
        int sum = 0;
        for(int i = 0 ; i < nums.size() ; i++){
            sum += nums[i];
        }
        
        if(sum & 1){
            return false;
        }
        
        int target = sum / 2;
        
        vector<vector<int>> dp(n+1, vector<int>(target+1, 0));
        
        for(int i = 1 ; i <= n; i++){
            for(int j = 0; j <= target ; j++){
                if( j >= nums[i-1]){
                    dp[i][j] = max(dp[i-1][j], dp[i-1][j-nums[i-1]] + nums[i-1]);
                }
                else{
                    dp[i][j] = dp[i-1][j];
                }
            }
        }
        
        bool ans = (dp[nums.size()][target] == target ?  true : false) ;
        
        return ans;
    }
};