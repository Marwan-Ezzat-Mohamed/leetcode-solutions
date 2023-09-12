class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int rows= matrix.size();
        int cols = matrix[0].size();
        
        int l=0, r= (rows*cols)-1;
        while(l<=r){
            int mid = (l+r)>>1;
            int j = mid % cols;
            int i = (mid - j)/cols;
            if(matrix[i][j] < target){
                l = mid +1;
            }else if(matrix[i][j] > target){
                r= mid-1;
            }
            else{
                return true;
            }
        }
        
        return false;
        
    }
};