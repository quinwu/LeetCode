class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int a = 0;
        int b = 0;
        for(auto num:nums){
            a = a ^ num & ~b;
            b = b ^ num & ~a;
        }
        return a|b;
    }
};