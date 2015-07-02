/* ----------------- Solution 1: Recursion ----------------- */
/*int dp[100000];

class Solution {
public:
    int numTrees(int n) {
        memset(dp, -1, sizeof(dp));
        return DP(n);
    }

    int DP(int n){
        if(n == 0 || n == 1) return 1;
        if(dp[n] != -1) return dp[n];

        int ans = 0;
        for(int i = 1; i <= n; i++){
            dp[i-1] = DP(i-1);
            dp[n-i] = DP(n-i);
            ans += dp[i-1] * dp[n-i];
        }
        return ans;
    }
};*/


/* ----------------- Solution 2: Iteration ----------------- */
class Solution {
public:
    int numTrees(int n) {
        vector<int> dp;
        dp.push_back(1); // dp[0] = 1

        for(int i = 1; i <= n; i++){
            dp.push_back(0);
            for(int j = 1; j <= i; j++){
                dp[i] += dp[j-1] * dp[i-j];
            }
        }
        return dp[n];
    }
};
