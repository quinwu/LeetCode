class Solution {
public:
    // direct
    // 0 = to right
    // 1 = down
    // 2 = to left
    // 3 = up
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        if (matrix.empty())
            return {};
        
        vector<int> ans;
        int row = matrix.size();
        int col = matrix[0].size();
        
        int left = 0;
        int right = col - 1;
        int up = 0;
        int bottom = row - 1;
        int direct = 0;
        
        while(ans.size() < row * col){
            switch (direct){
                case 0:
                    for(int i = left ; i <= right ; i++){
                        ans.push_back(matrix[up][i]);
                    }
                    up++;
                    break;
                case 1:
                    for(int i = up ; i <= bottom ; i++){
                        ans.push_back(matrix[i][right]);
                    }
                    right --;
                    break;
                case 2:
                    for(int i = right ; i >= left ; i--){
                        ans.push_back(matrix[bottom][i]);
                    }
                    bottom--;
                    break;
                case 3: 
                    for(int i = bottom ; i >= up ; i--){
                        ans.push_back(matrix[i][left]);
                    }
                    left++;
                    break;
            }
            direct = (direct + 1) % 4;
        }
        
        return ans;
    }
};