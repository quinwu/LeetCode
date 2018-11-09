class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int size = nums.size();
        k %= size;
        int count = 0;
        for(int start = 0 ; count < size ; start++){
            int cur = start;
            int prev = nums[start];
            do{
                int next = (cur + k) % size;
                int t = nums[next];
                nums[next] = prev;
                prev = t;
                cur = next;
                count ++;
            }while(start != cur);
        }
    }
};