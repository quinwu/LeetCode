class Solution {
public:
    int maxProfit(vector<int>& prices) {
        
        if(prices.empty()){
            return 0;
        }
        
        int n = prices.size();
        
        vector<int> left(n,0);
        vector<int> right(n,0);
        
        int minn = prices.front();
        
        for(int i = 1 ; i < n ; i++){
            left[i] = max(left[i-1], prices[i]-minn);
            minn = min(minn, prices[i]);
        }
        
        int maxn = prices.back();
        for(int i = n -2 ; i >= 0 ; i--){
            right[i] = max(right[i+1], maxn - prices[i]);
            maxn = max(maxn, prices[i]);
        }

        int ans = 0 ;
        for(int i = 2; i <= n ; i++){
            int tmp = left[i-1] + (i == n ? 0 : right[i]);
            ans = max(ans, tmp);
        }
        
        return ans;
    }
};