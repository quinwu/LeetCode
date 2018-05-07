class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        vector<int> result;
        int l1 = 0,l2 = 0;
        while(l1 < nums1.size() && l2 < nums2.size()){
            if(nums1[l1] < nums2[l2]){
                result.push_back(nums1[l1++]);
            }
            else{
                result.push_back(nums2[l2++]);
            }
        }
        while(l1 < nums1.size()){
            result.push_back(nums1[l1++]);            
        }
        while(l2 < nums2.size()){
            result.push_back(nums2[l2++]);
        }
        
        if(result.size() & 1){
            return result[result.size()/2];
        }
        else{
            return (result[result.size()/2] + result[result.size()/2 -1])/2.0;
        }
    }
};