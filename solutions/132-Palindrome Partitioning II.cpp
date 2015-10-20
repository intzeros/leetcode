/* -------------------------- O(n^2) --------------------------*/

#define N 2000

class Solution {
public:
    int minCut(string s) {
        int dp[N];
        int n = s.size();
        for(int i = 0; i < n; i++){
            dp[i] = i;
        }

        bool flag[N][N];    //flag[i][j] = true, if s(i, j) is a palindrome.
        memset(flag, false, sizeof(flag));

        for(int i = 1; i < n; i++){
            for(int j = i; j >= 0; j--){
                if(s[i] == s[j] && (i-j < 2 || flag[j+1][i-1])){
                    flag[j][i] = true;
                    if(j == 0){
                        dp[i] = 0;
                    }else {
                        dp[i] = min(dp[i], dp[j-1] + 1);
                    }
                }
            }
        }

        return dp[n-1];
    }
};
