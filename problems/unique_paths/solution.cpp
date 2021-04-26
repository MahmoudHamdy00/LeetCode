class Solution {
	int dp[105][105];
public:
	int uniquePaths(int m, int n) {
		memset(dp, 0, sizeof dp);
		dp[n][m + 1] = 1;
		for (int i = n; i > 0; i--) {
			for (int j = m; j > 0; j--) {
				dp[i][j] = dp[i + 1][j] + dp[i][j + 1];
			}
		}
		return dp[1][1];
    }

};