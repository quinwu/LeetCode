class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        set<int> Hash1;
        set<int> Hash2;
        vector<int> ans;
        for(int i = 0 ; i < nums1.size() ; i++){
            Hash1.insert(nums1[i]);
        }
        for(int i = 0 ; i < nums2.size() ; i++){
            Hash2.insert(nums2[i]);
        }
        for(auto it = Hash1.begin() ,end = Hash1.end() ; it != end ; it++){
            if(Hash2.count(*it)){
                ans.push_back(*it);
            }
        }
        return ans;
    }
};