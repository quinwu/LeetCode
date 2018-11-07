class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        vector<int> ans;
        for(vector<int>::iterator it = numbers.begin(); it != numbers.end(); it++){
            int another = target - *it;
            vector<int>::iterator iter = lower_bound(it+1, numbers.end(), another);
            if(another == *iter){
                ans.push_back(it-numbers.begin()+1);
                ans.push_back(iter-numbers.begin()+1);
                break;
            }    
        }
        return ans;
    }
};