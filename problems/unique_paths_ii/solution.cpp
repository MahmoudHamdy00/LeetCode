class Solution {
    int mem[100][100];
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        memset(mem,-1,sizeof mem);
        return uniquePathsWithObstacles(0,0,obstacleGrid);
    }
    int uniquePathsWithObstacles(int i ,int j,vector<vector<int>>& obstacleGrid) {
        if(i>=obstacleGrid.size()||j>=obstacleGrid[0].size()||obstacleGrid[i][j])return 0;
        if(i==obstacleGrid.size()-1&&j==obstacleGrid[0].size()-1)return 1;
        int &ret=mem[i][j];
        if(~ret)return ret;
        ret=uniquePathsWithObstacles(i+1,j,obstacleGrid);
        ret+=uniquePathsWithObstacles(i,j+1,obstacleGrid);
        return ret;
    }
    
};