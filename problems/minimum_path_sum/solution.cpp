class Solution {
public:
    int n,m;
    vector<vector<int>> g,vis;
    int minPathSum(vector<vector<int>>& grid) {
        for(int i=1;i<grid.size();i++){
            grid[i][0]+=grid[i-1][0];
        }
        for(int j=1;j<grid[0].size();j++){
            grid[0][j]+=grid[0][j-1];
        }
        for(int i=1;i<grid.size();i++){
           for(int j=1;j<grid[0].size();j++){
            grid[i][j]+=min(grid[i][j-1],grid[i-1][j]);
          }
        }
        return grid.back().back();
    }
   
};