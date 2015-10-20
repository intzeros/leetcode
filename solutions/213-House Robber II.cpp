class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        if(n == 0) return 0;
        if(n == 1) return nums[0];

        int ans0 = rob_between(nums, 0, n-2);   //第一天到倒数第二天
        int ans1 = rob_between(nums, 1, n-1);   //第二天到最后一天

        return max(ans0, ans1);
    }

    int rob_between(vector<int>& nums, int s, int e){
        int dp[2];
        dp[0] = 0;
        dp[1] = nums[s];
        for(int i = s+1; i <= e; i++){
            int tmp = dp[0];
            dp[0] = max(dp[0], dp[1]);
            dp[1] = tmp + nums[i];
        }
        return max(dp[0], dp[1]);
    }
};
