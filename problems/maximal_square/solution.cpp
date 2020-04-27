class Solution
{
public:
	int maximalSquare(vector<vector<char>> &matrix)
	{
		int rows = matrix.size(), cols = rows > 0 ? matrix[0].size() : 0;
		if (!rows || !cols)
			return 0;
		vector<vector<char>> dp(rows + 1, vector<char>(cols + 1));
		int maxsqlen = 0;
		dp[1][1] = (int)matrix[0][0] - '0';
		for (int i = 1; i <= rows; i++)
		{
			for (int j = 1; j <= cols; j++)
			{
				if (matrix[i - 1][j - 1] == '1')
				{
					dp[i][j] = min({dp[i][j - 1], dp[i - 1][j], dp[i - 1][j - 1]}) + 1;
					maxsqlen = max(maxsqlen, (int)dp[i][j]);
				}
			}
		}
		return maxsqlen * maxsqlen;
	}
};