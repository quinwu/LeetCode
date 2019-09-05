class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        vector<int> ans;
        
        unordered_map<int, int> m1;
        unordered_map<int, int> m2;
        
        for(auto i : nums1){
            m1[i] ++;
        }
        
        for(auto i : nums2){
            m2[i] ++;
        }
        
        for(auto it : m1){
            while(it.second -- > 0 && m2[it.first]-- > 0){
                ans.push_back(it.first);
            }
        }
        
        return ans;
        
    }
};