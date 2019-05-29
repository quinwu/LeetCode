class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ans;
        int size = nums.size();
        int subsize = 1 << size;
        for(int i = 0 ; i < subsize ; i ++){
            vector<int> subset;
            int index = i;
            int cnt = 0;
            while(index){
                int flag = index & 1;
                if(flag){
                    subset.push_back(nums[cnt]);
                }
                cnt ++;
                index = index >> 1;
            }
            ans.push_back(subset);
        }
        return ans;
    }
};