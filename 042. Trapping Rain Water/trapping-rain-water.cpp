class Solution {
public:
    int trap(vector<int>& height) {
        int ans = 0;
        int l = 0 ;
        int r = height.size() - 1;
        
        while( l < r){
            int min_num = min(height[l], height[r]);
            
            if(height[l] < height[r]){
                l++;
                while( l < r && height[l] < min_num){
                    ans += min_num - height[l++];
                }
            }
            else{
                r--;
                while( l < r && height[r] < min_num){
                    ans += min_num - height[r--];
                }
            }
        }
        return ans;
    }
    
};