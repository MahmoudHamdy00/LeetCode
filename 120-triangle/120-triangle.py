class Solution:
    mem: List[List[int]]
    def minimumTotal(self, triangle: List[List[int]]) -> int:
        dp=[[0]*(len(triangle)+1) for i in range (len(triangle)+2)]
        for i in range(len(triangle)-1,-1,-1):
            for j in range(i+1):
                dp[i][j]=triangle[i][j]+min(dp[i+1][j],dp[i+1][j+1]);
        return dp[0][0];
