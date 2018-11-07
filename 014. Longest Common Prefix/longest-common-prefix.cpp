class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if(strs.size() == 0){
            return "";
        }
        if(strs.size() == 1){
            return strs[0];
        }
        string ans = strs[0];
        for(int i = 1; i < strs.size(); i++){
            string prefix = "";
            for(int j = 0 ; j < strs[i].length() && j < ans.length() ; j++){
                if(ans[j] == strs[i][j]){
                    prefix += strs[i][j];
                }
                else{
                    break;
                }
            }
            ans = prefix;
        }
        return ans;
    }
};