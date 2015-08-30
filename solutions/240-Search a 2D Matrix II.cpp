class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int n = matrix.size();
        if(n == 0) return false;
        int m = matrix[0].size();
        
        int i = 0, j = m-1;
        while(true){
            while(i < n && matrix[i][j] < target) i++;
            if(i < 0 || i >= n) break;
            while(matrix[i][j] > target) j--;
            if(j < m && j < 0 || j >= m) break;
            
            if(matrix[i][j] == target) return true;
        }
        return false;
    }
};
