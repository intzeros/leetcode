class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
    	int n = triangle.size();
    	if(n == 0) return 0;
    	vector<int> dp;		//滚动数组
    	for(int j = 0; j < triangle[n-1].size(); j++){
    		dp.push_back(triangle[n-1][j]);
    	}

        for(int i = n-2; i >= 0; i--){
        	for(int j = 0; j < triangle[i].size(); j++){
        		dp[j] = triangle[i][j] + (dp[j] < dp[j+1] ? dp[j] : dp[j+1]);
        	}
        }
        return dp[0];
    }
};
