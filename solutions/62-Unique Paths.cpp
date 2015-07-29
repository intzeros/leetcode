/* ----------------- Solution 1 ----------------- */
/*class Solution {
public:
    int uniquePaths(int m, int n) {
        int dp[101][101];
        for(int i = 0; i < m; i++){
        	for(int j = 0; j < n; j++){
        		if(i == 0 && j == 0){
        			dp[0][0] = 1;
        		}else if(i == 0){
        			dp[0][j] = dp[0][j-1];
        		}else if(j == 0){
        			dp[i][0] = dp[i-1][0];
        		}else{
        			dp[i][j] = dp[i-1][j] + dp[i][j-1];
        		}
        	}
        }
        return dp[m-1][n-1];
    }
};*/

/* ----------------- Solution 2: 滚动数组 ----------------- */
class Solution {
public:
    int uniquePaths(int m, int n) {
        int dp[101];
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(i == 0 && j == 0){
                    dp[0] = 1;
                }else if(i == 0){
                    dp[j] = dp[j-1];
                }else{
                    dp[j] += dp[j-1];
                }
            }
        }
        return dp[n-1];
    }
};
