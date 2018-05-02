class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if (nums.size() == 0){
            return 0;
        }
        int flag = nums[0];
        int index = 1;
        for (int i = 1 ; i < nums.size() ; i++){
            if( flag != nums[i]){
                flag = nums[i];
                nums[index] = nums[i];
                index ++;
            }
        }
        return index;
    }
};