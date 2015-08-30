class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int n = matrix.size();
        if(n == 0) return false;
        int m = matrix[0].size();
        
        int k = 0;
        while(k < n && target > matrix[k][m-1]) k++;
        if(k == n) return false;
        
        int i = 0, j = m-1, mid;
        while(i <= j){
            mid = (i+j)>>1;
            if(matrix[k][mid] == target) return true;
            else if(matrix[k][mid] > target) j = mid-1;
            else i = mid+1;
        }
        
        return false;
    }
};
