class Solution {
public:
    vector<int> sortArrayByParityII(vector<int>& A) {
        
        int n = A.size();
        int i = 0; // even
        int j = 1; // odd
        
        while( i < n && j < n){
            
            // current position is even
            if(A[i] % 2 == 0){
                i += 2;
            }
            
            // current position is odd
            if(A[j] % 2 == 1){
                j += 2;
            }
            
            if( i < n && j < n && A[i] % 2 == 1 && A[j] % 2 == 0){
                std::swap(A[i], A[j]);
            }
            
        }
        return A;
    }
};