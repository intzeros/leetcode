class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        if(n == 0) return 0;

        int dp[2];    //滚动数组
        dp[0] = 0;
        dp[1] = nums[0];

        for(int i = 1; i < n; i++){
            int tmp = dp[0];
            dp[0] = max(dp[0], dp[1]);
            dp[1] = tmp + nums[i];
        }

        return max(dp[0], dp[1]);
    }
};
