class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        vector<int> temp;
        for (int i = 0 ; i < m ; i++){
            temp.push_back(nums1[i]);
        }
        int cnt = 0;
        int i =0, j = 0;
        while (i < m && j < n){
            if(temp[i] < nums2[j]){
                nums1[cnt++] = temp[i++];
            }
            else{
                nums1[cnt++] = nums2[j++];
            }
        }
        
        while( i < m ){
            nums1[cnt++] = temp[i++];
        }
        while( j < n ){
            nums1[cnt++] = nums2[j++];
        }
    }
};