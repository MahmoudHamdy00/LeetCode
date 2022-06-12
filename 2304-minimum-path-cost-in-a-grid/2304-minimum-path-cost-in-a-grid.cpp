class Solution {
    vector<vector<int>>mem;
public:
    int minPathCost(vector<vector<int>>& grid, vector<vector<int>>& moveCost) {
        mem=vector<vector<int>>(55,vector<int>(55,-1));
        int ret=1e9;
        for(int i=0;i<grid[0].size();++i){
            ret=min(ret,minPathCost(0,i,grid,moveCost));
        }
        return ret;
    }
    int minPathCost(int i,int j,vector<vector<int>>& grid, vector<vector<int>>& moveCost) {
        if(i==grid.size()-1)return grid[i][j];
        int &ret=mem[i][j];
        if(~ret)return ret;
        ret=1e9;
        for(int nxt=0;nxt<grid[i].size();++nxt){
            ret=min(ret,minPathCost(i+1,nxt,grid,moveCost)+grid[i][j]+moveCost[grid[i][j]][nxt]);
        }
        return ret;
    }
};