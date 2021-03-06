class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int,int> m;
        for(int i = 0 ; i < nums.size(); i ++){
            m[nums[i]] = i;
        }
        vector<int> ans;
        for(int i = 0 ; i < nums.size(); i++){
            int t = target - nums[i];
            if(m.count(t) && m[t] != i){
                ans.push_back(i);
                ans.push_back(m[t]);
                break;
            }
        }
        return ans;
    }
};