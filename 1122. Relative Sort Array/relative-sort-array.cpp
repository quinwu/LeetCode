class Solution {
public:
    vector<int> relativeSortArray(vector<int>& arr1, vector<int>& arr2) {
        map<int, int> m;
        for(auto i : arr1){
            m[i] ++;
        }
        vector<int> ans;   
        for(auto i : arr2){
            while(m[i]){
                ans.push_back(i);
                m[i]--;
            }
        }
        for (auto it : m){
            while( it.second ){
                ans.push_back(it.first);
                it.second --;
            }
        }
        return ans;
    }
};