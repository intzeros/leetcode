/* ----------------- Solution 1: Recursion ----------------- */
/*int dp[1000][1000];

class Solution {
public:
    int DP(vector<vector<int> >& grid, int x, int y){
        if(dp[x][y] != -1) return dp[x][y];
        if(x == 0 && y == 0) return dp[x][y] = grid[0][0];
        if(x == 0) return dp[x][y] = DP(grid, 0, y-1) + grid[x][y];
        if(y == 0) return dp[x][y] = DP(grid, x-1, 0) + grid[x][y];

        return dp[x][y] = min(DP(grid, x-1, y), DP(grid, x, y-1)) + grid[x][y];
    }

    int minPathSum(vector<vector<int> >& grid) {
        int m = grid.size();
        if(m == 0) return 0;
        int n = grid[0].size();
        memset(dp, -1, sizeof(dp));
        return DP(grid, m-1, n-1);
    }
};*/


/* ----------------- Solution 2: Iteration ----------------- */
class Solution {
public:
    int minPathSum(vector<vector<int> >& grid) {
        int m = grid.size();
        if(m == 0) return 0;
        int n = grid[0].size();
        vector<vector<int> > dp(grid);

        for(int i = 0; i < m; i++){
        	for(int j = 0; j < n; j++){
        		if(i == 0 && j == 0) continue;
        		else if(i == 0) dp[i][j] += dp[0][j-1];
        		else if(j == 0) dp[i][j] += dp[i-1][0];
        		else dp[i][j] += min(dp[i-1][j], dp[i][j-1]);
        	}
        }
        return dp[m-1][n-1];
    }
};
