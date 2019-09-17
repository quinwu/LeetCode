class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {  
        int l = 0;
        int r = nums.size();
        int l_ans = -1;
        while( l < r){
            int mid = l + ( r - l) / 2;
            if(nums[mid] < target){
                l = mid + 1;
            }
            else{
                r = mid;
            }
        }
        
        l_ans = r;
        
        l = 0;
        r = nums.size();
        
        int r_ans = -1;
        while( l < r ){
            int mid = l + (r - l) / 2;
            
            if(nums[mid] <= target){
                l = mid + 1;
            }
            else{
                r = mid;
            }
        }
        
        r_ans = r-1;
    
        vector<int> ans;
        if(r_ans < l_ans){
            l_ans = -1;
            r_ans = -1;
        }
        ans.push_back(l_ans);
        ans.push_back(r_ans);
        
        return ans;
    }
};