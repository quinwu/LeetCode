class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        
        if(intervals.size() == 0){
            return intervals;
        }
        
        vector<vector<int>> ans;
        
        sort(intervals.begin(), intervals.end(), [](auto& i1, auto& i2){return i1[0]<i2[0];});
        
        ans.push_back(intervals[0]);
        
        for(int i = 1 ; i < intervals.size() ; i++){
            if(intervals[i][0] <= ans[ans.size()-1][1]){
                if(intervals[i][1] >= ans[ans.size()-1][1]){
                    ans[ans.size()-1][1] = intervals[i][1];
                }
            }
            else{
                ans.push_back(intervals[i]);
            }
        }
        
        return ans;
        
    }
};