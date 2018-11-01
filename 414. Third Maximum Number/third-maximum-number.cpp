class Solution {
public:
    int thirdMax(vector<int>& nums) {
        set<int> Set;
        for(int num : nums){
            Set.insert(num);
            if(Set.size() > 3){
                Set.erase(Set.begin());
            }
        }
        return Set.size() == 3 ? *Set.begin():*Set.rbegin();
    }
};