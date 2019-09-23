class Solution {
public:
    int findMaximumXOR(vector<int>& nums) {
        int max = 0;
        int mask = 0;
        for(int i = 31; i >= 0 ; i --){
            set<int> hashset;
            mask = mask | ( 1 << i);
            for(int i = 0 ; i < nums.size(); i++){
                hashset.insert(mask & nums[i]);
            }
            
            int t = max | ( 1 << i);
            for(set<int>::iterator it = hashset.begin() ; it != hashset.end() ; it ++){
                int cur_XOR = t ^ *(it);
                if(hashset.find(cur_XOR) != hashset.end()){
                    max = t;
                    break;
                }
            }
            
        }
        return max;
    }
};