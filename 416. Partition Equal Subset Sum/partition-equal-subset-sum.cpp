class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int n = nums.size();
        if( n == 0){
            return false;
        }
        int sum = 0;
        for(int i = 0 ; i < n ; i++){
            sum += nums[i];
        }
        if(sum & 1){
            return false;
        }
        
        int target = sum >> 1;
        vector<int> dp(target+2,0);
        
        for(int i = 1 ; i <= n ; i++){
            for(int j = target ; j >= nums[i-1] ; j--){
                dp[j] = max(dp[j], dp[j-nums[i-1]] + nums[i-1]);
            }
        }
        
        
        bool ans = (dp[target] == target);
        return ans;
        
    }
};